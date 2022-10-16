#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll maxn = 1e5 + 5;
const ll maxm = 1e3 + 5;
inline void qread(){}
template<class T1, class ...T2>
inline void qread(T1 &IEE, T2&... ls){
	register T1 __ = 0, ___ = 1;
	register char ch;
	while(!isdigit(ch = getchar())) ___ = (ch == '-') ? -___ : ___;
	do{
		__ = (__ << 1) + (__ << 3) + (ch ^ 48);
	}while(isdigit(ch = getchar()));
	__ *= ___;
	IEE = __;
	qread(ls...);
	return ;
}
ll n, ans;
ll a[maxn];
int main(){
	ll t;
	qread(t);
	while(t--){
		qread(n);
		for(int i = 1;i <= n;i++){
			qread(a[i]);
		}
		sort(a + 1, a + n + 1);
		ans = 1;
		int now = 1;
		for(int i = 1;i <= n;i++){
			if(a[i] <= i){
				ans = i + 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}