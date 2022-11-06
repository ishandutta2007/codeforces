//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(ll (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;

ll T, a, b;
string s;

int main() {
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld%lld", &a, &b);
		cin>>s; ll n = s.length(); s = '0' + s;
		ll cnt = 1145141919810, ans = 0;
		rep(i, 1, n) {
			if(s[i]^48) {
				if(!(s[i-1]^48)) ans += min(cnt*b, a);
				cnt = 0;
			}
			else ++cnt;
		}
		printf("%lld\n", ans);
	}
	return 0;
}