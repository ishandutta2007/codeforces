#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define M 1000000007
#define N 5011
using namespace std;
typedef pair<int,int> pt;

int n;
string s;
pair<pt, int> p[N];
int c[20][N];
int dp1[N][N], add[N][N];
int dp2[N][N], fm[N][N];
int gg[N];
int it;

bool bigger(int x, int y, int xx, int yy) {
	int d = y - x + 1;
	if (d != yy - xx + 1) puts("!");
	int w = gg[d];
	if (c[w][x] > c[w][xx]) return 1;
	if (c[w][x] < c[w][xx]) return 0;

	if (c[w][y - pw(w) + 1] > c[w][yy - pw(w) + 1]) return 1;

	return 0;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> s;
	n = s.size();
	for (int i = 0; i < n; i++) p[i] = mp(mp(s[i], 0), i);
	sort(p, p + n);
	int e = 0;
	for (int i = 0; i < n; i++) {
		if (i > 0 && p[i - 1].F != p[i].F) e++;
		c[0][p[i].S] = e;
	}
	it = 0;
	while (pw(it) < n) {
		it++;
		for (int i = 0; i < n; i++) if (i + pw(it - 1) >= n) p[i] = mp(mp(c[it - 1][i], -1), i); else
		p[i] = mp(mp(c[it - 1][i], c[it - 1][i + pw(it - 1)]), i);
		sort(p, p + n);
		e = 0;
		for (int i = 0; i < n; i++) {
			if (i > 0 && p[i - 1].F != p[i].F) e++;
			c[it][p[i].S] = e;
		}
	}
	gg[1] = 0;
	for (int i = 2; i <= n; i++) gg[i] = gg[i / 2] + 1;	



	for (int i = 1; i <= n; i++) dp1[0][i] = 1;

	for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) dp2[i][j] = fm[i][j] = 1e9;
	for (int i = 1; i <= n; i++) dp2[0][i] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			add[i][j] += add[i][j - 1];
			if (add[i][j] >= M) add[i][j] -= M;
			
		}
		for (int j = 0; j <= n; j++) {
			dp1[i][j] += add[i][j];
			if (dp1[i][j] >= M) dp1[i][j] -= M;
		}			

		for (int j = 1; j <= n; j++) {
			fm[i][j] = min(fm[i][j], fm[i][j - 1]);
		}
		for (int j = 0; j <= n; j++) dp2[i][j] = min(dp2[i][j], fm[i][j]);

		for (int j = i + 1; j < n; j++) {
			if (s[j] == '0') continue;
			int len = j - i;

			int to = j + len - 1;

			if (to >= n) continue;
			if (bigger(i, j - 1, j, to)) to++;
			if (to >= n) continue;

			add[j][to + 1] += dp1[i][j];
			if (add[j][to + 1] >= M) add[j][to + 1] -= M;

		        fm[j][to + 1] = min(fm[j][to + 1], dp2[i][j] + 1);
		}
	}		
	int ans1 = 0;
	for (int i = 0; i < n; i++) {
		ans1 = (ans1 + dp1[i][n]) % M;
	}
	cout << ans1 << endl;

	string cur;
	cur.resize(n);

	for (int i = 0; i < cur.size(); i++) cur[i] = '0';
	while (cur.size() < 30) cur = "0" + cur;
	cur = "0" + cur;
	int was = -1;
	int pos = cur.size() - 1;
	string ans;
	for (int i = n - 1; i >= 0; i--) {
		cur[pos] = s[i];
		pos--;
		if (dp2[i][n] == 1e9) continue;
		if (was != -1 && was - i > 20) continue;
		string t = cur;

		int cut = dp2[i][n] + 1;
		for (int i = 0; i < 20; i++) if (cut & pw(i)) {
			t[t.size() - 1 - i]++;
		}
		for (int i = t.size() - 1; i > 0; i--) {
			if (t[i] > '1') {
				t[i - 1] ++;
				t[i] -= 2;
			}
		}
		if (was == -1) {
			ans = t;
		} else {
			ans = min(ans, t);
		}
		was = i;
	}
	long long out = 0;
	for (int i = 0; i < ans.size(); i++) out = (out * 2 + ans[i] - '0') % M;
	cout << out << endl;

	return 0;
}