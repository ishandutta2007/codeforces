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

TVector operator+(TVector a, TVector b) {
    return {a.x + b.x, a.y + b.y};
}

TVector operator-(TVector a, TVector b) {
    return {a.x - b.x, a.y - b.y};
}

TVector operator*(TVector a, ll k) {
    return {a.x * k, a.y * k};
}

ll operator*(TVector a, TVector b) {
    return a.x * b.y - a.y * b.x;
}

ll operator%(TVector a, TVector b) {
    return a.x * b.x + a.y * b.y;
}

double len(TVector a) {
    return sqrt(a % a);
}

struct TLine {
    ll a, b, c;
    TLine(TVector A, TVector B) {
        a = A.y - B.y;
        b = B.x - A.x;
        c = A.y * B.x - B.y * A.x;
    }
    double rast(TVector A) {
        double top = abs(a * A.x + b * A.y - c);
        double bot = sqrt(a * a + b * b);
        return top / bot;
    }
};

ll det(ll a, ll b, ll c, ll d) {
    return a * d - b * c;
}

pair <ll, TVector> intersection(TLine a, TLine b) {
    ll d = det(a.a, a.b, b.a, b.b);
    ll dx = det(a.c, a.b, b.c, b.b);
    ll dy = det(a.a, a.c, b.a, b.c);
    if (!d) {
        return {0, {0, 0}};
    }
    if (dx % d || dy % d) {
        return {-1, {0, 0}};
    }
    return {1, {dx / d, dy / d}};
}

ll calc(TVector A, TVector B) {
    ll x = abs(B.x - A.x);
    ll y = abs(B.y - A.y);
    return __gcd(x, y) + 1;
}

ostream &operator<<(ostream &out, TVector A) {
    out << "{" << A.x << ", " << A.y << "}";
    return out;
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
    ll res = 0;
    vector <pair <TVector, TVector> > segs(n);
    for (ll i = 0; i < n; i++) {
        TVector A, B;
        cin >> A.x >> A.y >> B.x >> B.y;
        //cout << A << " " << B << "\n";
        if (A.x == B.x) {
            if (A.y > B.y) {
                swap(A, B);
            }
        } else if (A.x > B.x) {
            swap(A, B);
        }
        res += calc(A, B);
        segs[i] = {A, B};
    }
    //cout << res << "\n";
    map <pair <ll, ll>, ll> cnt;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if (i == j) continue;
            TVector A = segs[i].first, B = segs[i].second, C = segs[j].first, D = segs[j].second;
            TLine l1 = TLine(A, B);
            TLine l2 = TLine(C, D);
            auto t = intersection(l1, l2);
            //cout << A << " " << B << " " << C << " " << D << " " << t.first << " " << t.second << "\n";
            if (t.first == 1) {
                if (t.second.x >= A.x && t.second.x <= B.x && t.second.x >= C.x && t.second.x <= D.x) {
                    if (t.second.y < min(A.y, B.y)) continue;
                    if (t.second.y > max(A.y, B.y)) continue;
                    if (t.second.y < min(C.y, D.y)) continue;
                    if (t.second.y > max(C.y, D.y)) continue;
                    cnt[{t.second.x, t.second.y}]++;
                    //cout << A << " " << B << " " << C << " " << D << " " << t.second << "\n";
                }
                continue;
            }
            if (t.first == -1) {
                continue;
            }
            if (l2.rast(A) > EPS) {
                continue;
            }
            cout << A << " " << B << " " << C << " " << D << " " << t.first << "\n";
        }
    }
    for (auto t : cnt) {
        //cout << t.second << "\n";
        res -= (int) sqrt(t.second);
    }
    cout << res;
}