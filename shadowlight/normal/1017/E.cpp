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

ostream &operator<<(ostream &out, TVector A) {
    out << "{" << A.x << ", " << A.y << "}";
    return out;
}

istream &operator>>(istream &in, TVector &A) {
    in >> A.x >> A.y;
    return in;
}

TVector O = {-1, -1};

bool operator<(TVector A, TVector B) {
    if ((A - O) * (B - O) == 0) {
        return len(A - O) < len(B - O);
    }
    return (A - O) * (B - O) < 0;
}

vector <TVector> convex(vector <TVector> ps) {
    ll n = ps.size();
    O = {INF, INF};
    for (ll i = 0; i < n; i++) {
        //cout << O << " " << ps[i] << "\n";
        if (O.x > ps[i].x) {
            O = ps[i];
        } else if (O.x == ps[i].x && O.y > ps[i].y) {
            O = ps[i];
        }
    }
    sort(ps.begin(), ps.end());
    vector <TVector> st;
    st.push_back(ps[0]);
    for (ll i = 1; i < n; i++) {
        TVector A = ps[i];
        while (st.size() > 1 && (st.back() - st[st.size() - 2]) * (A - st[st.size() - 2]) >= 0) {
            st.pop_back();
        }
        st.push_back(A);
    }
    while (st.size() > 2 && (st.back() - st[st.size() - 2]) * (st[0] - st[st.size() - 2]) >= 0) {
        st.pop_back();
    }
    return st;
}

vector <double> create(vector <TVector> ps) {
    ll n = ps.size();
    vector <double> res;
    for (ll i = 0; i < n; i++) {
        TVector A = ps[i], B = ps[(i + 1) % n], C = ps[(i + 2) % n];
        res.push_back(len(B - A));
        res.push_back(atan2((C - B) * (A - B), (C - B) % (A - B)));
    }
    return res;
}

bool isEqual(pair <double, ll> a, pair <double, ll> b) {
    return abs(a.first - b.first) < EPS && a.second == b.second;
}

bool zfunc(vector <double> &a, ll len) {
    ll n = a.size();
    vector <ll> z(n, 0);
    ll l = -1, r = -1;
    for (ll i = 1; i < n; i++) {
        if (r >= i) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && abs(a[i + z[i]] - a[z[i]]) < EPS) {
            z[i]++;
        }
        if (i + z[i] >= r) {
            l = i, r = i + z[i];
        }
    }
    for (ll i = 0; i < n; i++) {
        if (z[i] >= len) {
            return true;
        }
    }
    return false;
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
    ll n, m;
    cin >> n >> m;
    vector <TVector> a(n), b(m);
    for (ll i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    for (ll i = 0; i < m; i++) {
        cin >> b[i].x >> b[i].y;
    }
    a = convex(a);
    b = convex(b);
//    for (TVector x : a) {
//        cout << x << " ";
//    }
//    cout << "\n";
//    for (auto x : b) {
//        cout << x << " ";
//    }
//    cout << "\n";
    if (a.size() != b.size()) {
        cout << "NO\n";
        return 0;
    }
    auto ha = create(a), hb = create(b);
//    for (auto t : ha) {
//        cout << t << " ";
//    }
//    cout << "\n";
//    for (auto t : hb) {
//        cout << t << " ";
//    }
//    cout << "\n";
    for (ll i = 0; i < 2; i++) {
        auto nha = ha;
        for (auto t : hb) {
            nha.push_back(t);
        }
        for (auto t : hb) {
            nha.push_back(t);
        }
        if (zfunc(nha, ha.size())) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}