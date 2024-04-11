//In the name of God
#include <iostream>
using namespace std;
const int Maxn = 2e5 + 200;
int sum[Maxn];
int Min[Maxn];
int Max[Maxn];
int n;
bool check(int k){
	for(int i = 0; i <= n;i++){
		if(i + k <= n && Max[i+k] >= sum[i])
			return 1;
		if(i - k >= 0 && Min[i-k] <= sum[i])
			return 1;
	}
	return 0;
}
int bs(int L,int R){
	int mid = (L + R + 1) >> 1;
	if(L == R){
		if(check(mid))
			return mid;
		return 1;
	}
	if(check(mid))
		return bs(mid,R);
	return bs(L,mid-1);
}
int main(){
	string S;
	cin >> S;
	n = S.size();
	sum[0] = 0;
	for(int i = 0; i < n;i++){
		if(S[i] == 'a' || S[i] == 'A' || S[i] == 'e' || S[i] == 'E' || S[i] == 'o' || S[i] == 'O' || S[i] == 'i' || S[i] == 'I' || S[i] == 'u' || S[i] == 'U'){
			sum[i+1] = sum[i] - 1;
		}else
			sum[i+1] = sum[i] + 2;
	}
	if(sum[n] == -n){
		cout << "No solution" << endl;
		return 0;
	}
	Min[0] = 0;
	for(int i = 1; i <= n;i++){
		Min[i] = min(Min[i-1],sum[i]);
	}
	Max[n] = sum[n];
	for(int i = n-1; i >= 0;--i){
		Max[i] = max(Max[i+1],sum[i]);
	}
	int ans = bs(1,n);
	cout << ans << ' ';
	int cnt = 0;
	for(int i = 0; i <= n-ans;i++){
		if(sum[ans+i] - sum[i] >= 0)
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}