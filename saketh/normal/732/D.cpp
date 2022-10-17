#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M;
    cin >> N >> M;

    vi days(N);
    for (int i = 0; i < N; i++) {
        cin >> days[i];
        days[i]--;
    }

    vi prep(M);
    for (int i = 0; i < M; i++)
        cin >> prep[i];

    vi order(M);
    for (int i = 0; i < M; i++)
        order[i] = i;

    int ans = N + 1;
    int lo = 1, hi = N;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;

        vi last(M);
        for (int i = 0; i < mi; i++)
            if (days[i] != -1)
                last[days[i]] = max(last[days[i]], i);

        sort(all(order), [&](int a, int b) {
            return last[a] < last[b];
        });

        bool ok = true;
        int total = 0;
        for (int i = 0; i < order.size(); i++) {
            total += prep[order[i]];
            if (total + i > last[order[i]])
                ok = false;
        }

        if (ok) {
            ans = mi;
            hi = mi - 1;
        } else lo = mi + 1;
    }

    if (ans > N) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}