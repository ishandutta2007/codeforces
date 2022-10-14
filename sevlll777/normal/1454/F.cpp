#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        vector<int> B = A;
        sort(B.begin(), B.end());
        for (int i = 0; i < n; i++) {
            A[i] = (int) (lower_bound(B.begin(), B.end(), A[i]) - B.begin());
        }
        vector<int> sufmax(n + 1, -1);
        for (int i = n - 1; i >= 0; i--) sufmax[i] = max(sufmax[i + 1], A[i]);
        vector<int> last(n + 1);
        for (int i = 0; i < n; i++) last[A[i]] = i;
        vector<int> sufmaxlast(n + 1, -1);
        sufmaxlast[n - 1] = last[n - 1];
        for (int i = n - 2; i >= 0; i--) sufmaxlast[i] = max(sufmaxlast[i + 1], last[i]);
        int loh = (int) ceil(log2(n + 11));
        vector<vector<int>> ST(n, vector<int>(loh));
        for (int i = 0; i < n; i++) ST[i][0] = A[i];
        for (int l = 1; l < loh; l++) {
            for (int i = 0; i < n; i++) {
                if ((i + (1 << (l - 1))) < n) {
                    ST[i][l] = min(ST[i][l - 1], ST[i + (1 << (l - 1))][l - 1]);
                } else {
                    ST[i][l] = ST[i][l - 1];
                }
            }
        }
        vector<int> LOG(n * 9 + 1);
        for (int i = 2; i < n * 9 + 1; i++) {
            LOG[i] = LOG[i / 2] + 1;
        }
        int mem = 0;
        int f = 0;
        for (int i = 0; i < n - 2; i++) {
            if (f == 1) break;
            mem = max(mem, A[i]);
            int l = i, r = n;
            while (r - l > 1) {
                int m = (l + r) / 2;
                int d = m - (i + 1) + 1;
                int mim = min(ST[i + 1][LOG[d]], ST[m - (1 << LOG[d]) + 1][LOG[d]]);
                if (mim <= mem) {
                    r = m;
                } else {
                    l = m;
                }
            }

            int l2 = i, r2 = n;
            while (r2 - l2 > 1) {
                int m = (l2 + r2) / 2;
                int d = m - (i + 1) + 1;
                int mim = min(ST[i + 1][LOG[d]], ST[m - (1 << LOG[d]) + 1][LOG[d]]);
                if (mim < mem) {
                    r2 = m;
                } else {
                    l2 = m;
                }
            }

            int l1 = l+1, r1 = r2;
            if (l1 <= r1-1) {
                while (r1 - l1 > 1) {
                    int m = (l1 + r1) / 2;
                    if (sufmax[m] == mem) {
                        cout << "YES\n";
                        cout << i + 1 << ' ' << m - 1 - (i + 1) + 1 << ' ' << n - m << '\n';
                        f = 1;
                        break;
                    }
                    if (sufmax[m] < mem) {
                        r1 = m;
                    } else {
                        l1 = m;
                    }
                }
                if (f == 0) {
                    int m = l1 + 1;
                    if (sufmax[m] == mem) {
                        cout << "YES\n";
                        cout << i + 1 << ' ' << m - 1 - (i + 1) + 1 << ' ' << n - m << '\n';
                        f = 1;
                        break;
                    }
                }
            }
        }
        if (f == 0) cout << "NO\n";
    }


}