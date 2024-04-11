#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second

using namespace std;
using LL = long long;
using pii = pair<int, int>;

const int NN = 111;
char s[NN][NN];
int flag[NN][NN], n, m, k, ans[NN][NN];
char r[NN];

int calc(int a, int b, int c, int d) {
	if(d == 0) return 0;
	d--;
	if(d<b*(a+1)) return d/(a+1);
	d-=b*(a+1);
	return b+d/a;
}

void solve() {
	scanf("%d %d %d", &n, &m, &k);
	for(int i=0; i<n; i++) scanf("%s", s+i);
	vector<pii> v;
	for(int i=0; i<n; i++) {
		if(i&1) {
			for(int j=m-1; j>=0; j--) v.pb(pii(i, j));
		}else {
			for(int j=0; j<m; j++) v.pb(pii(i, j));
		}
	}
	int tot=0;
	for(int i=0; i<n; i++) for(int j=0; j<m; j++) if(s[i][j] == 'R') tot++;
	int f=tot/k, g=tot%k, cur=0;
	for(int i=0; i<v.size(); i++) {
		if(s[v[i].x][v[i].y] == 'R') cur++;
		ans[v[i].x][v[i].y]=r[calc(f, g, k, cur)];
	}
	for(int i=0; i<n; i++, puts("")) for(int j=0; j<m; j++) putchar(ans[i][j]);
}

int main() {
#ifdef KN
	freopen("A.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif // KN
	int T;
	for(int i=0; i<26; i++) r[i]='a'+i, r[i+26]='A'+i;
	for(int i=52; i<62; i++) r[i]='0'+i-52;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}