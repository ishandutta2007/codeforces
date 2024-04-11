#include <bits/stdc++.h>
#define forn(i,n) for (int i = 0; i < (n); ++i)
#define forab(i,a,b) for (int i = (a); i < (b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define X first
#define Y second
#define db(x) cout << #x << " = " << x << '\n'

#ifdef LOCAL
    #define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
    #define eprintf(args...) ;
#endif

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> ipair;
typedef pair<ll, ll> lpair;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double EPS = 1e-9;

const int N = 2022;

struct Vec2 {
    ll x, y;
    Vec2 operator + (Vec2 const& b) const { return {x + b.x, y + b.y}; }
    Vec2 operator - (Vec2 const& b) const { return {x - b.x, y - b.y}; }

    int half() const {
        if (y > 0)
            return 0;
        if (y < 0)
            return 1;
        if (x > 0)
            return 0;
        return 1;
    }
};

ll dot(Vec2 const& a, Vec2 const& b) {
    return a.x*b.x + a.y*b.y;
}
ll cross(Vec2 const& a, Vec2 const& b) {
    return a.x*b.y - a.y*b.x;
}

int n;
Vec2 ps[N];

bool read() {
    if (scanf("%d", &n) < 1) {
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        ps[i] = {x, y};
    }
    return 1;
}

void solve() {
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        static Vec2 vs[N];
        int n1 = 0;
        for (int j = 0; j < n; ++j)
            if (i != j)
                vs[n1++] = ps[j] - ps[i];
        sort(vs, vs + n1, [](Vec2 const& a, Vec2 const& b) {
            int h1 = a.half();
            int h2 = b.half();
            if (h1 != h2)
                return h1 < h2;
            return cross(a, b) > 0;
        });

        int k = 0;
        for (int j = 0; j < n1; ++j) {
            while (true) {
                int k1 = (k + 1);
                if (k1 == n1)
                    k1 = 0;
                if (cross(vs[j], vs[k1]) > 0)
                    k = k1;
                else
                    break;
            }
            int cnt1 = (k + n1 - j) % n1;
            int cnt2 = n1 - 1 - cnt1;
            ans += (cnt1*(cnt1-1LL)/2) * (cnt2*(cnt2-1LL)/2);
            if (k == j)
                ++k;
        }
    }
    cout << ans / 2 << "\n";
}

int main() {
#ifdef LOCAL
    assert(freopen("E.in", "r", stdin));
#endif

    while (read()) {
        solve();
    }

    return 0;
}