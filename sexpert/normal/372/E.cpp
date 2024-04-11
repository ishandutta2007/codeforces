#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const int MAX = 1e4 + 5;
ll p2[MAX];

struct frc {
    ll p, q;
    frc(ll _p = 0, ll _q = 1) : p(_p), q(_q) {
        ll g = __gcd(abs(p), abs(q));
        p /= g;
        q /= g;
        if(q < 0) {
            q *= -1;
            p *= -1;
        }
    }

    frc operator+(frc o) {
        ll nm = p * o.q + q * o.p, dn = q * o.q;
        return frc(nm, dn);
    }

    frc operator-(frc o) {
        ll nm = p * o.q - q * o.p, dn = q * o.q;
        return frc(nm, dn);
    }

    frc operator*(frc o) {
        ll nm = p * o.p, dn = q * o.q;
        return frc(nm, dn);
    }

    frc operator/(frc o) {
        ll nm = p * o.q, dn = q * o.p;
        return frc(nm, dn);
    }

    bool operator<(frc o) const {
        return p * o.q < q * o.p;
    }

    bool operator==(frc o) const {
        return p * o.q == q * o.p;
    }
};

struct pt {
    frc x, y;
    pt (frc _x, frc _y) : x(_x), y(_y) {}
    pt operator+(pt &o) {
        return pt(x + o.x, y + o.y);
    }
    pt operator-(pt &o) {
        return pt(x - o.x, y - o.y);
    }
    pt operator/(frc f) {
        return pt(x/f, y/f);
    }
    bool operator<(const pt &o) const {
        return tie(x, y) < tie(o.x, o.y);
    }
};

ostream& operator<< (ostream& out, const frc &f) {
    out << f.p << "/" << f.q;
    return out;
}

ostream& operator<< (ostream& out, const pt &p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}
vector<pt> pts;

pt dir(pt p, pt q) {
    pt z = q - p;
    frc ze = frc(0, 1);
    if(z.x == ze)
        return pt(ze, frc(1, 1));
    else
        return pt(frc(1, 1), z.y/z.x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    p2[0] = 1;
    for(int i = 1; i < MAX; i++)
        p2[i] = (p2[i - 1] * 2) % MOD;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        frc x = frc(a, b), y = frc(c, d), z = x * x + y * y;
        //cout << x << " " << y << " " << z << '\n';
        pts.push_back({frc(x/z), frc(y/z)});
    }

    //for(auto &p : pts)
    //    cout << p << '\n';

    map<pt, ll> tot, cancer;
    map<pair<pt, pt>, int> fuckoff;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            pt p1 = pts[i], p2 = pts[j];
            tot[p1 + p2] = 1;
            cancer[p1 + p2] = 1;
            fuckoff[make_pair(p1 + p2, dir(p1, p2))]++;
        }
    }

    ll ans = 0;

    for(auto &[pa, x] : fuckoff) {
        //cout << pa.first << " " << pa.second << " " << x << '\n';
        tot[pa.first] = (tot[pa.first] * (x + 1)) % MOD;
        cancer[pa.first] += x;
    }

    for(auto &[p, x] : tot) {
        //cout << p << " " << x << " " << cancer[p] << '\n';
        ans = (ans + x - cancer[p]) % MOD;
    }

    cout << (ans + MOD) % MOD << '\n';
}

/*
(-1, 1) -> (-1/2, 1/2)
(-2, 1) -> (-2/5, 1/5)
(1, 1) -> (1/2, 1/2)
(2, 1) -> (2/5, 1/5)
(-3, 1) -> (-3/10, 1/10)
(3, 1) -> (3/10, 1/10)
*/