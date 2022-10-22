#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int m, n;
string s[110];
int k[110];
bool e[110];

int main() {
	cin >> m >> n;
	rep(i, m) cin >> s[i];
	rep(i, n) {
		cin >> k[i];
		--k[i];
		e[k[i]] = 1;
	}

	string cur;

	rep(i, n) {
		if (cur != "" && cur.size() != s[k[i]].size()) {
			puts("No");
			return 0;
		}
		if (cur == "") {
			cur = s[k[i]];
		} else {
			rep(j, cur.size()) {
				if (cur[j] != '?' && cur[j] != s[k[i]][j]) {
					cur[j] = '?';
				}
			}
		}
	}

	rep(i, m) if (!e[i]) {
		if (cur.size() != s[i].size()) continue;
		bool m = 1;
		rep(j, cur.size()) {
			if (cur[j] != '?' && cur[j] != s[i][j]) {
				m = 0;
			}
		}
		if (m) {
			puts("No");
			return 0;
		}
	}
	
	puts("Yes");
	cout << cur << endl;

	return 0;
}