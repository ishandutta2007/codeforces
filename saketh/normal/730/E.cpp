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

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vi a(N), d(N);

    for (int i = 0; i < N; i++)
        cin >> a[i] >> d[i];

    int ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            pair<int, int> i1 = { a[i], i },
                           i2 = { a[i] + d[i], i },
                           j1 = { a[j], j },
                           j2 = { a[j] + d[j], j };

            int fi = int(comp(i1, j1) ^ comp(i2, j1))
                   + int(comp(i2, j1) ^ comp(i2, j2));

            int fj = int(comp(i1, j1) ^ comp(i1, j2))
                   + int(comp(i1, j2) ^ comp(i2, j2));

            ans += max(fi, fj);
        }
    }

    cout << ans << endl;
    return 0;
}