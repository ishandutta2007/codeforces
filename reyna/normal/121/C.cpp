//In the name of God
#include <iostream>
using namespace std;
const int Maxn = 14;
long long f[Maxn];
int take[Maxn];
int ans[Maxn];
int len_lucky(int x,int les){
	int ret = 0;
	for(int mask = 0; mask < (1 << x);mask++){
		long long cur = 0;
		for(int i = 0; i < x;i++)
			if((1 << i) & mask)
				cur *= 10,cur += 4;
			else
				cur *= 10,cur += 7;
		if(cur <= les)
			ret++;
	}
	return ret;
}
int find_lucky(int x){
	int ret = 0;
	for(int i = 1; i <= 10;i++)
		ret += len_lucky(i,x);
	return ret;
}
int fact(int n){
	if(!n)
		return 1;
	return fact(n-1) * n;
}
bool is_lucky(int x){
	while(x){
		if(x % 10 != 4 && x % 10 != 7)
			return 0;
		x /= 10;
	}
	return 1;
}
int main(){
	int n,k;
	cin >> n >> k;
	for(int i = 0; i < Maxn;i++)
		f[i] = fact(i);
	if(n < Maxn && k > f[n]){
		cout << -1 << endl;
		return 0;
	}
	--k;
	int best = -1;
	int out = find_lucky(n);
	for(int i = Maxn-1; i >= 0;--i){
		for(int j = 1; j < Maxn;j++)
			if(k < j * f[i]){
				k -= (j-1) * f[i];
				ans[i] = j-1;
				if(j-1)
					if(best == -1)
						best = i;
				break;
			}
		
	}
	for(int i = best; i + 1;--i){
		int cur = 0;
		int in = 0;
		for(int j = 0; j < Maxn;j++){
			cur += take[j] ^ 1;
			if(cur == ans[i]+1){
				in = j;
				take[j] = 1;
				break;
			}
		}
		int now = n - best + in;
		int pl = n - i;
	//W	cout << now << ' ' << pl << endl;
		if(is_lucky(now) && !is_lucky(pl))
			out--;
	}
	cout << out << endl;
	return 0;
}