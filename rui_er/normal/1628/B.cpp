//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T, n, a[N];
string s[N], rev;
map<string, int> mp;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
bool valid(int id) {
	if(a[id] == 1) return 1;
	if(a[id] == 2 && s[id][0] == s[id][1]) return 1;
	if(a[id] == 3 && s[id][0] == s[id][2]) return 1;
	return 0;
}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, n) {
			cin>>s[i];
			a[i] = s[i].length();
		}
		int ok = 0;
		rep(i, 1, n) if(valid(i)) {ok = 1; break;}
		if(!ok) {
			rep(i, 1, n) {
				rev = s[i];
				reverse(rev.begin(), rev.end());
				if(mp[rev]) {ok = 1; break;}
				rev = s[i].substr(1);
				reverse(rev.begin(), rev.end());
				if(mp[rev]) {ok = 1; break;}
				rep(j, 'a', 'z') {
					rev = (char)j + s[i];
					reverse(rev.begin(), rev.end());
					if(mp[rev]) {ok = 1; break;}
				}
				if(ok) break;
				mp[s[i]] = 1;
			}
			mp.clear();
		}
		puts(ok?"YES":"NO");
	}
	return 0;
}