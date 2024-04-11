#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vector<pair<int, int>> photos;

    for (int i = 0; i < N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if (a + b >= c + d) {
            photos.emplace_back(a, b);
            photos.emplace_back(c, d);
        } else if (a - d > 0) {
            photos.emplace_back(a - d, d - a);
        } else if (b - c > 0) {
            photos.emplace_back(c - b, b - c);
        }
    }

    ll ans = 0;
    vector<int> vals;

    for (auto p : photos) {
        vals.push_back(p.first + p.second);
        ans -= p.second;
    }

    sort(all(vals), greater<ll>());

    for (int i = 0; i < vals.size(); i+=2) {
        ans += vals[i];
    }

    cout << ans << endl;
    return 0;
}