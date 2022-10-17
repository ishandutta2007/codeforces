#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e15;
const int MAXN = 1e5 + 100;

int N, M;
int a[MAXN];
int b[MAXN];

ll cost(ll bound) {
    ll res = 0;

    for (int i = 0; i < N; i++)
        if (a[i] < bound)
            res += bound - a[i];

    for (int j = 0; j < M; j++)
        if (b[j] > bound)
            res += b[j] - bound;

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> a[i];

    for (int j = 0; j < M; j++) 
        cin >> b[j];

    ll ans = INF;
    ll lo = 0, hi = 1e9;

    while (lo <= hi) {
        ll wid = (hi - lo) / 3;

        ll v1 = cost(lo + wid);
        ll v2 = cost(lo + 2 * wid);

        ans = min(ans, min(v1, v2));

        if (v1 < v2) {
            hi = lo + 2 * wid - 1;
        } else {
            lo = lo + wid + 1;
        }
    }

    cout << ans << "\n";
}