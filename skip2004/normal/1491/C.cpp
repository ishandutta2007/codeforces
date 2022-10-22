#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;

typedef unsigned long long u64;
typedef double db;
typedef long long ll;
typedef unsigned u32;
const int N = 5005;
int t, n;
int s[N];
ll ad[N], fr[N];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> t;
	rep(i, 1, t) {
		cin >> n;
		rep(i, 1, n) cin >> s[i];
		ll cost=0;
		rep(i, 1, n) {
			fr[i]+=ad[i]+=ad[i-1];
			if(fr[i]<s[i]) cost+=s[i]-fr[i]-1,fr[i]=s[i]-1;
			fr[i+1]+=fr[i]-s[i]+1;
			ad[i+2]+=1;
			ad[std::min(i+s[i]+1,n+1)]-=1;
		}
		cout<<cost<<'\n';
		memset(fr, 0, sizeof(fr));
		memset(ad, 0, sizeof(ad));
	}
}