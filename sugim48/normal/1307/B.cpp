#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < (N); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back

using ll = long long;
using i_i = tuple<int, int>;

int f(vector<int> a, int x) {
    int N = a.size();
    rep(i, N) if (a[i] == x) return 1;
    int ma = 0;
    rep(i, N) ma = max(ma, a[i]);
    return max(2, (x + ma - 1) / ma);
}

int main() {
    int T; cin >> T;
    while (T--) {
        int N, x;
        scanf("%d%d", &N, &x);
        vector<int> a(N);
        rep(i, N) scanf("%d", &a[i]);
        printf("%d\n", f(a, x));
    }
}