#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)123;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

pair<int, int> s[N];
int a[N];

bool dpL[N][N];
int prL[N][N];

bool dpR[N][N];
int prR[N][N];

int ind[N], hhp[N];
int n, m;

void countDpL(int x) {
	for (int i = x - 1; i >= 0; i--) {
		if (ind[i] == -1) continue;
		int num = ind[i];
		int hp = hhp[num];

		for (int j = i + 1; !dpL[x][num] && j <= x; j++) {
			hp += a[j];
			if (hp < 0) break;
			if (j == x || (ind[j] != -1 && dpL[x][ind[j]])) {
				dpL[x][num] = true;
				prL[x][num] = (j == x ? -2 : ind[j]);
			}
		}
	}
}

void countDpR(int x) {
	for (int i = x + 1; i < n; i++) {
		if (ind[i] == -1) continue;
		int num = ind[i];
		int hp = hhp[num];

		for (int j = i - 1; !dpR[x][num] && j >= x; j--) {
			hp += a[j];
			if (hp < 0) break;
			if (j == x || (ind[j] != -1 && dpR[x][ind[j]])) {
				dpR[x][num] = true;
				prR[x][num] = (j == x ? -2 : ind[j]);
			}
		}
	}
}

vector<int> kkL(int x, int num) {
	vector<int> ans;
	while (num != -2) {
		ans.push_back(num);
		num = prL[x][num];
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

vector<int> kkR(int x, int num) {
	vector<int> ans;
	while (num != -2) {
		ans.push_back(num);
		num = prR[x][num];
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

void add(vector<int> &a, const vector<int> &b) {
	for (int i = 0; i < (int)b.size(); i++) {
		a.push_back(b[i]);
	}
}

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dpL[i][j] = dpR[i][j] = false;
			prL[i][j] = prR[i][j] = -1;
		}
		ind[i] = -1;
	}

	cin >> n >> m;

	int h_first = 0, h_last = 0;

	for (int i = 0; i < m; i++) {
		cin >> s[i].first >> s[i].second;
		s[i].first--;
		hhp[i] = s[i].second;
		ind[s[i].first] = i;	

		if (s[i].first < s[h_first].first) h_first = i;
		if (s[i].first > s[h_last].first) h_last = i;
	}

	if (m == 1) {
		cout << s[0].first + 1 << "\n1\n";
		return;
	}
	//sort(s, s + m);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		countDpL(i);
		countDpR(i);
	}

	for (int i = 0; i < n; i++) {
		bool ok = false;
		vector<int> v;
		if (s[h_first].first >= i && dpR[i][h_last]) {
			v = kkR(i, h_last);	
			ok = true;		
		} else if (s[h_last].first <= i && dpL[i][h_first]) {
			v = kkL(i, h_first);
			ok = true;
		} else if (s[h_first].first < i && s[h_last].first > i + 1 && dpL[i][h_first] && dpR[i + 1][h_last]) {
			v = kkL(i, h_first);
			add(v, kkR(i + 1, h_last));
			ok = true;
		}

		if (ok) {
			cout << i + 1 << "\n";
			vector<bool> u(m, false);
			for (int x: v) u[x] = true;
			for (int i = 0; i < (int)v.size(); i++) cout << v[i] + 1 << " ";
			for (int i = 0; i < m; i++) if (!u[i]) cout << i + 1 << " ";
			cout << "\n";
			return;
		}
	}

	cout << "-1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 1;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}