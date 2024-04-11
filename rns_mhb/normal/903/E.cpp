#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define f1(i, a, b) for (int i = a; i <= b; i ++)

#define N 5005

int n, k, g[30], h[30], a[N], now;

string s[N];
vector <int> v[N];

bool check(int x, int y) {
	string t = s[1];
	swap(t[x], t[y]);
	int g;
    f1(i, 2, k) {
    	g = 0;
        f0(j, 0, n) if (t[j] != s[i][j]) g ++;
        if (max(now * 2, g) != 2) return 0;
    }
    return 1;
}

int main() {
	ios::sync_with_stdio(true); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    scanf("%d %d ", &k, &n);
	f1(i, 1, k) cin >> s[i];
    if (k == 1) {
        swap(s[1][0], s[1][1]);
        cout << s[1] << endl;
        return 0;
    }
	f1(i, 0, n) g[s[1][i] - 'a'] ++;
    f0(i, 0, 26) if (g[i] > 1) now = 1;
    bool flag = 0;
    if (n <= 26) {
        f1(i, 2, k) {
        	memset(h, 0, sizeof h);
			f0(j, 0, n) h[s[i][j] - 'a'] ++;
			f0(j, 0, 26) if (h[j] != g[j]) {
                puts("-1");
                return 0;
			}
        }
        f0(i, 0, n) f0(j, i+1, n) if (check(i, j)) {
			swap(s[1][i], s[1][j]);
			cout << s[1] << endl;
			flag = 1; return 0;
        }
        if (!flag) puts("-1");
    }
    else {
		int p = 0;
		f1(i, 2, k) {
			memset(h, 0, sizeof h);
			f0(j, 0, n) {
				h[s[i][j] - 'a'] ++;
				if (s[1][j] != s[i][j]) v[i].pb(j);
			}
			f0(j, 0, 26) if (g[j] != h[j]) flag = 1;
			if (v[i].size() > 4) flag = 1;
			if (v[i].size() > 2) p = i;
		}
		if (flag) puts("-1");
		else {
			if (p == 0) cout << s[1] << endl;
			else {
				int sz = v[p].size();
				f0(i, 0, sz) f0(j, i+1, sz) if (check(v[p][i], v[p][j])) {
					swap(s[1][v[p][i]], s[1][v[p][j]]);
					cout << s[1] << endl;
					flag = 1; return 0;
				}
				if (!flag) puts("-1");
			}
		}
	}
	return 0;
}