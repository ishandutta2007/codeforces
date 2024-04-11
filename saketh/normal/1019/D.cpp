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

struct point {
    ll x, y;
    point(ll x = 0, ll y = 0): x(x), y(y) {}

    point operator +(point q) const { return point(x + q.x, y + q.y); }
    point operator -(point q) const { return point(x - q.x, y - q.y); }

    ll operator *(point q) const { return x * q.x + y * q.y; }
    ll operator %(point q) const { return x * q.y - y * q.x; }

    friend ostream& operator <<(ostream &os, const point &p) {
        return os << p.x << " " << p.y;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    ll S;
    cin >> N >> S;

    vector<point> pts(N);
    vi ord(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        pts[i] = point(x, y);
        ord[i] = i;
    }

    sort(all(ord), [&](int i, int j) {
        return (pts[i].y != pts[j].y) ? pts[i].y < pts[j].y : pts[i].x < pts[j].x;
    });
    vi loc(N);
    for (int i = 0; i < N; i++)
        loc[ord[i]] = i;

    vector<array<int, 2>> events;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++)
            if (loc[j] > loc[i])
                events.push_back({ i, j });
            else
                events.push_back({ j, i });
    }
    sort(all(events), [&](auto &a, auto &b) {
        return (pts[a[1]] - pts[a[0]]) % (pts[b[1]] - pts[b[0]]) > 0;
    });

    for (auto &e : events) {
        int p = e[0], q = e[1];

        auto search = [&](ll T) {
            int lo = 0, hi = N - 1;
            while (lo <= hi) {
                int mi = (lo + hi) / 2;
                ll A = (pts[q] - pts[p]) % (pts[ord[mi]] - pts[p]);
                if (A == 2 * T) {
                    cout << "Yes\n" << pts[p] << "\n" << pts[q] << "\n" << pts[ord[mi]] << "\n";
                    exit(0);
                } if (A < 2 * T) {
                    lo = mi + 1;
                } else {
                    hi = mi - 1;
                }
            }
        };
        search(S);
        search(-S);

        swap(ord[loc[p]], ord[loc[q]]);
        swap(loc[p], loc[q]);
    }

    cout << "No\n";
    return 0;
}