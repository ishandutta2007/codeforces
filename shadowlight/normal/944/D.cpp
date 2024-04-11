#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
const int Q = 31;
const int N = 5007;

int cnt[Q][N][Q];

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    string s;
    cin >> s;
    int n = s.size();
    vector <int> cnt1(Q, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            int a = s[i] - 'a', b = s[(i + j) % n] - 'a';
            cnt[a][j][b]++;
        }
        cnt1[s[i] - 'a']++;
    }
    cout.precision(20);
    double res = 0;
    for (int i = 0; i < Q; i++) {
        int now = 0;
        for (int j = 1; j < n; j++) {
            int val = 0;
            for (int k = 0; k < Q; k++) {
                if (cnt[i][j][k] == 1) {
                    val++;
                }
            }
            now = max(now, val);
        }
        //cout << i << " " << val << "\n";
        res += (double) now / (double) n;
    }
    cout << res << "\n";
}