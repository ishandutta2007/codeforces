//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;

string a, b, r; int n, m, dis[26][26], ans;
char read() {char c = getchar(); for(;!isalpha(c);c=getchar()); return c;}

int main() {
	cin>>a>>b; n = a.length();
	if(b.length() != n) return puts("-1"), 0;
	scanf("%d", &m); fil(dis, 0x3f);
	rep(i, 0, 25) dis[i][i] = 0;
	while(m--) {
		char c1 = read(), c2 = read();
		int k; scanf("%d", &k);
		dis[c1-'a'][c2-'a'] = min(dis[c1-'a'][c2-'a'], k);
	}
	rep(k, 0, 25) rep(i, 0, 25) rep(j, 0, 25) dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
	rep(i, 0, n-1) {
		char p = a[i], q = b[i];
		if(p == q) {r += p; continue;}
		int _ = inf, __ = -1;
		rep(j, 0, 25) if(_ > dis[p-'a'][j] + dis[q-'a'][j]) {_ = dis[p-'a'][j] + dis[q-'a'][j]; __ = j;}
		if(_ == inf) return puts("-1"), 0;
		ans += _; r += (__ + 'a');
	}
	printf("%d\n", ans); cout<<r<<endl;
	return 0;
}