#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 3007;
const double EPS = 1e-8;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n, q, m;
    cin >> n >> m >> q;
    const int N = (1 << n);
    vector <int> cnt(N, 0);
    vector <int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    reverse(w.begin(), w.end());
    vector <vector <int> > res(N, vector <int> (MAXN, 0));
    for (int i = 0; i < m; i++) {
        int d = 0;
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            d = d * 2 + (c - '0');
        }
        //cout << d << "\n";
        cnt[d]++;
    }
     for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int sumw = 0;
            for (int k = 0; k < n; k++) {
                if (((i >> k) & 1) == ((j >> k) & 1)) {
                    sumw += w[k];
                }
            }
            //cout << i << " " << j << " " << sumw << "\n";
            res[i][sumw] += cnt[j];
        }
        for (int j = 1; j < MAXN; j++) {
            res[i][j] = res[i][j] + res[i][j - 1];
        }
    }
    for (int i = 0; i < q; i++) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        int d = 0;
        for (char c : s) {
            d = d * 2 + c - '0';
        }
        //cout << d << " " << k << "\n";
        cout << res[d][k] << "\n";
    }
}