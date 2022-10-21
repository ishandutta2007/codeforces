#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long

using namespace std;

const int N = 200500;
const int inf = 1e9 + 50;
const int mod = 998244353;

int A[N];

int main() {
    int tcase;
    scanf("%d", &tcase);
    while (tcase--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
        vector<int> V[2];
        for (int i = 1; i <= n; i++) {
            int b;
            scanf("%d", &b);
            V[A[i]].push_back(b);
        }
        if (V[0].empty() || V[1].empty()) {
            ll s = 0;
            for (auto x : V[0]) s += x;
            for (auto x : V[1]) s += x;
            printf("%lld\n", s);
            continue;
        }
        sort(V[0].begin(), V[0].end());
        sort(V[1].begin(), V[1].end());
        reverse(V[0].begin() + 1, V[0].end());
        reverse(V[1].begin(), V[1].end());
        ll s = V[0][0];
        for (int i = 1, j = 0, p = 0; i < V[0].size() || j < V[1].size(); ) {
            if (p == 0) {
                if (j < V[1].size()) s += 2 * V[1][j++], p = 1;
                else s += V[0][i++], p = 0;
            }
            else {
                if (i < V[0].size()) s += 2 * V[0][i++], p = 0;
                else s += V[1][j++], p = 1;
            }
        }

        reverse(V[0].begin() + 1, V[0].end());
        reverse(V[1].begin(), V[1].end());
        reverse(V[1].begin() + 1, V[1].end());
        reverse(V[0].begin(), V[0].end());
        ll ss = V[1][0];
        for (int i = 0, j = 1, p = 1; i < V[0].size() || j < V[1].size(); ) {
            if (p == 0) {
                if (j < V[1].size()) ss += 2 * V[1][j++], p = 1;
                else ss += V[0][i++], p = 0;
            }
            else {
                if (i < V[0].size()) ss += 2 * V[0][i++], p = 0;
                else ss += V[1][j++], p = 1;
            }
        }
        printf("%lld\n", max(s, ss));
    }

    return 0;
}