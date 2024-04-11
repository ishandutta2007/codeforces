#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll nc2(ll n) {
    return n * (n - 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    vi x(N), y(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    vi vert;
    vector<array<int, 4>> other;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int dx = x[i] - x[j],
                dy = y[i] - y[j];
            if (dx < 0) {
                dx *= -1;
                dy *= -1;
            }

            if (dx == 0) {
                vert.push_back(x[i]);
            } else {
                array<int, 4> res = { dy, dx, dx * y[i] - dy * x[i], dx };
                int g0 = gcd(res[0], res[1]);
                int g2 = gcd(res[2], res[3]);
                res[0] /= g0;
                res[1] /= g0;
                res[2] /= g2;
                res[3] /= g2;
                other.push_back(res);
            }
        }
    }

    sort(all(vert));
    vert.erase(unique(all(vert)), vert.end());

    sort(all(other));
    other.erase(unique(all(other)), other.end());

    ll ans = nc2(vert.size() + other.size()) - nc2(vert.size());
    int str = 1;
    for (int i = 1; i < other.size(); i++) {
        if (other[i][0] == other[i-1][0] && other[i][1] == other[i-1][1]) {
            str++;
        } else {
            ans -= nc2(str);
            str = 1;
        }
    }
    ans -= nc2(str);

    cout << ans << endl;

    return 0;
}