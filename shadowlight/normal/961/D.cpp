#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;

struct TVector {
    ll x, y;
};

struct TLine {
    ll a, b, c;
    TLine(TVector A, TVector B) {
        a = A.y - B.y;
        b = B.x - A.x;
        c = A.y * B.x - B.y * A.x;
        ll x = __gcd(a, __gcd(b, c));
        a /= x, b /= x, c /= x;
        if (a < 0) {
            a *= -1, b *= -1, c *= -1;
        }
    }
    ll rast(TVector A) {
        return a * A.x + b * A.y - c;
    }
};

bool operator<(TLine a, TLine b) {
    if (a.a != b.a) {
        return a.a < b.a;
    }
    if (a.b != b.b) {
        return a.b < b.b;
    }
    return a.c < b.c;
}

bool operator==(TLine a, TLine b) {
    return !(a < b) && !(b < a);
}

bool operator!=(TLine a, TLine b) {
    return !(a == b);
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    ll n;
    cin >> n;
    vector <TVector> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    map <TLine, vector <int> > q;
    for (ll i = 1; i < n; i++) {
        q[TLine(a[0], a[i])].push_back(i);
    }
    if (q.size() <= 2) {
        cout << "YES\n";
        return 0;
    }
    auto it = q.begin();
    vector <vector <int> > mas(3);
    for (int i = 0; i < 3; i++) {
        mas[i] = it->second;
        it++;
    }
    for (ll i = 0; i < 3; i++) {
        for (ll j = i + 1; j < 3; j++) {
            TLine l = TLine(a[mas[i][0]], a[mas[j][0]]);
            vector <int> bad;
            vector <int> good(n, 0);
            for (int k = 0; k < n; k++) {
                if (k != mas[i][0] && l != TLine(a[mas[i][0]], a[k])) {
                    bad.push_back(k);
                    good[k] = 1;
                }
            }
            if (bad.size() <= 2) {
                cout << "YES\n";
                return 0;
            }
            int v = bad[0], u = bad[1];
            TLine l1 = TLine(a[v], a[u]);
            bool can = true;
            for (int k = 0; k < n; k++) {
                if (!good[k]) continue;
                if (k == v) continue;
                if (l1 != TLine(a[k], a[v])) {
                    can = false;
                    break;
                }
            }
            if (can) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}