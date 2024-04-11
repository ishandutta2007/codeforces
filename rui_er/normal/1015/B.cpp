//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 55;

int n, a[N], cnt[26];
char s[N], t[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
queue<int> pos[26];
vector<int> ans;

int main() {
	scanf("%d%s%s", &n, s+1, t+1);
	rep(i, 1, n) ++cnt[s[i]-'a'];
	rep(i, 1, n) --cnt[t[i]-'a'];
	rep(i, 0, 25) if(cnt[i]) return puts("-1")&0;
	rep(i, 1, n) pos[t[i]-'a'].push(i);
	rep(i, 1, n) {
		a[i] = pos[s[i]-'a'].front();
		pos[s[i]-'a'].pop();
	}
	rep(i, 1, n) {
		int swp = 0;
		rep(j, 1, n-1) {
			if(a[j] > a[j+1]) {
				swap(a[j], a[j+1]);
				ans.push_back(j);
				swp = 1;
			}
		}
		if(!swp) break;
	}
	int sz = ans.size();
	printf("%d\n", sz);
	rep(i, 0, sz-1) printf("%d%c", ans[i], " \n"[i==sz-1]);
	return 0;
}