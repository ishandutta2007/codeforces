#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const int M = 200;

int p[N], n, m, v1, v2, c, ans, q;

int fnd(int v) {
    return (v == p[v] ? v : p[v] = fnd(p[v]));
}

void uniq(int v1, int v2) {
    p[fnd(v1)] = fnd(v2);
}

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    for (int i = 0; i < N; i++) p[i] = i;

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2 >> c;
        v1--;
        v2--;
        uniq(v1 + c * M, v2 + c * M);
    }
    cin >> q;
    while (q--) {
        cin >> v1 >> v2;
        v1--;
        v2--;
        ans = 0;
        for (int c = 1; c <= m; c++)
            ans += int(fnd(v1 + c * M) == fnd(v2 + c * M));
        cout << ans << "\n";
    }

    //return 0;
}