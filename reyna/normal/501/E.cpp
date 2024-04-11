//In the name of God
#include <iostream>
using namespace std;
const int Maxn = 2e6 + 1e3;
int arr[Maxn];
int num[Maxn];
int n;
void clear(){
	for(int i = 0; i < Maxn;i++)
		num[i] = 0;
}
bool in(int L,int R,int now){
	if(L <= now && now < R)
		return 1;
	return 0;
}
int Ans = 0;
bool check(int L,int R){
	for(int i = L; i < R;i++)
		num[arr[i]]++;
	for(int i = L; i < R;i++){
		if(!in(L,R,n - i - 1))
			num[arr[n-i-1]]--;
		if(num[arr[n-i-1]] < 0){
			clear();
			return 0;
		}
	}
	for(int i = 0; i < n;i++){
		if(!in(L,R,i) && !in(L,R,n-i-1) && arr[i] != arr[n-i-1]){
			clear();
			return 0;
		}
	}
	int odd = 0;
	for(int i = 0; i < Maxn;i++){
		if(num[i] < 0){
			clear();
			return 0;
		}
		if(num[i] % 2)
			odd++;
	}
//	if(R == 2 && !Ans)
//		cerr << odd << endl;
	clear();
	if(n % 2)
		odd += 1 - in(L,R,n/2);
	if(odd == n % 2)
		return 1;
	return 0;
}
int bs(int L,int R,int st){
	int mid = (L + R) >> 1;
//	cerr << st << " --> " << L << ' ' << R << endl;
	if(R - L <= 1){
		if(check(st,mid+1) && R != L)
			return mid;
		else
			return Maxn;
	}
	if(check(st,mid+1))
		return min(mid,bs(L,mid,st));
	return bs(mid+1,R,st);
}
int main(){
	cin >> n;
	for(int i = 0; i < n;i++){
		cin >> arr[i];
	}
	if(!check(0,n)){
		cout << 0 << endl;
		return 0;
	}
	int fst = -1;
	for(int i = 0; i < n/2;i++){
		if(arr[i] != arr[n-i-1]){
			fst = i;
			break;
		}
	}
	if(fst == -1){
		cout << ((long long)n * (n + 1))/2 << endl;
		return 0;
	}
	long long x = fst,y = bs(fst,n,fst);
//	cerr << endl << endl;
	for(int i = 0; i < n/2;i++)
		swap(arr[i],arr[n-i-1]);
	Ans = Maxn;
	long long Y = n - fst - 1,X = n - bs(fst,n,fst) - 1;
	long long ans = 0;
//	cerr << endl;
	cerr << x << ' '<< y << " | " << X << ' ' << Y << endl;
	ans += max((X - x),(long long)0) * (fst + 1);
	ans += max((Y - y),(long long)0) * (fst + 1);
	ans += (fst + 1) * (fst + 1);
	cout << ans << endl;
	return 0;
}