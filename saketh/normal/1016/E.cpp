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

double project(double x, double y, double lx, double ly) {
    return x + (lx - x) * y / (y - ly);
}

double in(double l1, double r1, double l2, double r2) {
    return max(0., min(r1, r2) - max(l1, l2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int S, A, B, N;
    cin >> S >> A >> B >> N;

    N += 2;
    vector<array<double, 2>> f;
    f.push_back({-1, 1});
    for (int i = 1; i < N - 1; i++) {
        int l, r;
        cin >> l >> r;
        f.push_back({ double(l), double(r) });
    }
    f.push_back({1e9+1, 1e9+1});

    vll sum(N + 1);
    for (int i = 0; i < N; i++)
        sum[i+1] = sum[i] + f[i][1] - f[i][0];

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int x, y;
        cin >> x >> y;

        double x1 = project(x, y, A, S);
        double x2 = project(x, y, B, S);

        auto it1 = lower_bound(all(f), array<double, 2>{ x1, -1 });
        auto it2 = prev(lower_bound(all(f), array<double, 2>{ x2, -1 }));
        double cov = max(0LL, sum[it2 - f.begin()] - sum[it1 - f.begin()]);
        it1 = prev(it1);

        cov += in((*it1)[0], (*it1)[1], x1, x2);
        if (it1 != it2) cov += in((*it2)[0], (*it2)[1], x1, x2);

        cout << cov / (x2 - x1) * (B - A) << "\n";
    }

    return 0;
}