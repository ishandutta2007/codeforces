#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
const int M = 1504;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

vector<pair<int, int>> seg;

int dp[M][M];
int mx[M][M];
inline bool go(const vector<int> &v, int max_num, int need0) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			dp[i][j] = mx[i][j] = 0;
		}
	}
    int n = v.size();
    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + 1 - v[i - 1];
    }

    for (int i = 0; i < (int)seg.size(); i++) {
        dp[i][1] = pref[seg[i].second + 1] - pref[seg[i].first];
        if (dp[i][1] >= need0) return true;
        mx[i][1] = max(dp[i][1], (i > 0 ? mx[i - 1][1] : 0));
    }

    vector<int> prev((int)seg.size());
    for (int s = 0; s < (int)seg.size(); s++) {
        int pr = 0;
        while (seg[pr].second < seg[s].first) pr++;
        prev[s] = pr;
    }

    for (int num = 2; num <= max_num; num++) {
        for (int s = num - 1; s < (int)seg.size(); s++) {
            int pr = prev[s];
            int val = dp[pr][num - 1] + pref[seg[s].second + 1] - pref[seg[pr].second + 1];
            if (pr > 0) {
                val = max(val, mx[pr - 1][num - 1] + dp[s][1]);
            }
            dp[s][num] = val;
            mx[s][num] = max(mx[s - 1][num], val);
            if (val >= need0) return true;
        }
    }

    return false;
}

void solve() {
    int n, s, m, k;
    cin >> n >> s >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> tmp(s);
    seg.clear();
    for (int i = 0; i < s; i++) {
        cin >> tmp[i].first >> tmp[i].second;
        tmp[i].first--;
        tmp[i].second--;
    }

    for (int i = 0; i < s; i++) {
        bool ok = true;
        for (int j = 0; j < s; j++) {
            if (i == j) continue;
            if (tmp[j].first == tmp[i].first && tmp[j].second == tmp[i].second) {
                if (i < j) ok = false;
                continue;
            }
            if (tmp[j].first <= tmp[i].first && tmp[i].second <= tmp[j].second) {
                ok = false;
            }
        }
        if (ok) {
            seg.push_back(tmp[i]);
        }
    }
    sort(seg.begin(), seg.end());

    vector<int> v(n, 0);
    if (!go(v, min(m, (int)seg.size()), k)) {
        cout << "-1\n";
        return;
    }

    int L = -1;
    int R = INF;
    while (R - L > 1) {
        int M = (L + R) / 2;
        for (int i = 0; i < n; i++) {
            if (a[i] <= M) v[i] = 0;
            else v[i] = 1;
        }
        if (go(v, min(m, (int)seg.size()), k)) {
            R = M;
        } else {
            L = M;
        }
    }

    cout << R << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tst = 1;
    //scanf("%d", &tst);
    //cin >> tst;
#ifdef MADE_BY_SERT
    //freopen("input", "r", stdin);
    D = true;
	tst = 3;
	while (tst--) {
		solve();
	}
#else
    while (tst--) solve();
#endif
}