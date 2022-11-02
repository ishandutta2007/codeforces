#include <bits/stdc++.h>
using namespace std;
#define N 100100
#define M 33

char ss[M][M], sss[M];
string s[N], A;
int n, m, f[N], g[N], v[N], mv[N], num[N], win[N];
map <string, int> mp;

bool cmp(string s, string t) {
	return s.size() != t.size() ? s.size() < t.size() : s < t;
}

int main() {
//	freopen("f.in", "r", stdin);
	scanf("%d", &n);
	s[0] = "";
	for (int i = 1; i <= n; i ++) {
		scanf("%s", ss[i]);
		int len = strlen(ss[i]);
		for (int j = 0; j < len; j ++) {
			int Len = 0;
			for (int k = j; k < len; k ++) {
				sss[Len++] = ss[i][k];
				sss[Len] = 0;
				if (!mp.count(sss)) s[++m] = sss, mp[sss] = 1;
			}
		}
	}
	sort(s, s + m + 1, cmp);
	for (int i = 1; i <= m; i ++) {
		mp[s[i]] = i;
		for (int j = 0; j < s[i].size(); j ++) {
			int k = s[i][j] - 'a' + 1;
			v[i] += k, mv[i] = max(mv[i], k);
		}
		for (int j = 0; j < s[i].size(); j ++) sss[j] = s[i][j];
		sss[s[i].size()] = 0;
		for (int j = 1; j <= n; j ++) if (strstr(ss[j], sss)) num[i] ++;
	}

	for (int i = m; i >= 0; i --) {
		win[i] = 1;
		for (int j = 0; j < 26 * 2; j ++) {
			if (j < 26) A = char('a' + j) + s[i];
			else A = s[i] + char('a' + j % 26);
			int k = mp[A];
			if (!k) continue;
			if (win[k]) {win[i] = 0; break;}
			else win[i] = 1;
		}
	}

//	for (int i = 0; i <= m; i ++) cout << s[i] << ' ' << win[i] << endl; cout << endl;

	for (int i = m; i >= 0; i --) {
		for (int j = 0; j < 26 * 2; j ++) {
			if (j < 26) A = char('a' + j) + s[i];
			else A = s[i] + char('a' + j % 26);
			int k = mp[A];
			if (!k) continue;
			if (!win[i] && !win[k]) continue;
			int add = v[k] * mv[k] + num[k];
			if (f[i] < add + g[k]) f[i] = add + g[k], g[i] = f[k];
			else if (f[i] == add + g[k] && g[i] > f[k]) g[i] = f[k];
		}
	}
	printf("%s\n", win[0] ? "Second" : "First");
	printf("%d %d\n", f[0], g[0]);
	return 0;
}