//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define mulT0 int T; for(scanf("%d", &T);T;T--)
#define mulT1 int T, rnds; for(scanf("%d", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const int N = 1e3+5;

int n, k[N]; string s[N], winner;
map<string, int> mp, mp2;

int main() {
	scanf("%d", &n);
	rep(i, 1, n) {
		cin>>s[i]; scanf("%d", &k[i]);
		mp[s[i]] += k[i];
	}
	int mx = -0x3f3f3f3f, mxcnt = 0;
	for(map<string, int>::iterator it=mp.begin();it!=mp.end();it++) {
		if(it->second > mx) {
			mx = it->second;
			winner = it->first;
			mxcnt = 1;
		}
		else if(it->second == mx) ++mxcnt;
	}
	if(mxcnt == 1) cout<<winner<<endl;
	else {
		rep(i, 1, n) {
			mp2[s[i]] += k[i];
			if(mp[s[i]] == mx && mp2[s[i]] >= mx) {
				cout<<s[i]<<endl;
				break;
			}
		}
	}
	return 0;
}