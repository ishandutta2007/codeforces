#include <bits/stdc++.h>
using namespace std;
#define M 2020

int n, ini_pos;
vector<int> v[M];
int a[M], MAX;
map<int, int> mp;
int dist(int a, int b) {
	if (a < b) swap(a, b);
	return min(a - b, n - a + b);
}

void input() {
	scanf("%d %d", &n, &ini_pos);
	for (int i = 1; i <= n; i++) scanf("%d", a + i), mp[a[i]] = 0;
	for (map<int, int> :: iterator it = mp.begin(); it != mp.end(); it++) {
		mp[it->first] = ++MAX;
	}
	for (int i = 1; i <= n; i++) a[i] = mp[a[i]], v[a[i]].push_back(i);
}

int f[M], en[M];
int same[M], Same[M], nxt[M];
void prepare() {
	v[0].push_back(ini_pos);
	for (int m = MAX; m >= 0; m--) {
		if (m < MAX) {
			for (int i, j = 0; j < v[m].size(); j++) {
				i = v[m][j];
				int t = m ? i : 0;
				en[t] = -1;
                for (int ii, jj = 0; jj < v[m+1].size(); jj++) {
					ii = v[m+1][jj];
					int d = dist(i, ii);
                    if (en[t] == -1 || en[t] > d + f[ii]) {
						nxt[t] = ii;
						en[t] = d + f[ii];
                    }
                }
			}
		}
		if (!m) break;
		int s = v[m].size();
		for (int ii, i, j = 0; j < s; j++) {
			i = v[m][j];
			ii = v[m][(j+1)%s];
			same[i] = +1;
			Same[i] = ii;
			f[i] = en[ii] + (n - (ii >= i ? ii - i : ii - i + n));

			if (ii == i) {f[i] = en[ii]; continue;}
			ii = v[m][(j-1+s)%s];
			int ff = en[ii] + (n - (i >= ii ? i - ii : i - ii + n));
			if (f[i] > ff) f[i] = ff, same[i] = -1, Same[i] = ii;
		}
	}
}


void move(int a, int b) {
	int d = dist(a, b);
	if (d == b - a || d == b + n - a) printf("%+d\n", d);
	else printf("%+d\n", -d);
}

void a_a(int s, int cur, int type) {
    if (type == -1) reverse(v[s].begin(), v[s].end());
    for (int I = -1, i = 0; i < v[s].size(); i = (i + 1) % (int(v[s].size()))) {
		int t = v[s][i];
		if (I == -1) {
			if (t == cur) I = i;
			continue;
		}
		if (I == i) return;
		move(cur, t);
		cur = t;
    }
}

void solve() {
	int cur = ini_pos;
	printf("%d\n", en[0]);
	for (int s = 0; s < MAX;) {
		int t = nxt[s ? cur : 0];
        move(cur, t);
        cur = t;
        ++s;
        a_a(s, cur, -same[cur]);
        cur = Same[cur];
	}
}

int main() {
	//freopen("Edu4_F1.in", "r", stdin);
	input();
	prepare();
	solve();
	return 0;
}