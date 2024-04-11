#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

struct point{
    ll x, y;
    point() {}
    point(ll _x, ll _y) {
        x = _x, y = _y;
    }
};

ll gcd(ll a, ll b) {
    if (!a) return b;
    if (!b) return a;
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll gcd(ll a, ll b, ll c) {
    return max(1LL, gcd(abs(a), gcd(abs(b), abs(c))));
}

struct line{
    ll a, b, c;
    line() {}
    line(point x, point y) {
        a = y.y - x.y;
        b = x.x - y.x;
        c = x.y * y.x - x.x * y.y;
        ll g = gcd(a, b, c);
        a /= g;
        b /= g;
        c /= g;
        if (a < 0) {
            a *= -1, b *= -1, c *= -1;
        }
        if (a == 0 && b < 0) {
            b *= -1, c *= -1;
        }
        if (a == 0 && b == 0 && c < 0) {
            c *= -1;
        }
    }
};  

bool operator<(const line & a, const line & b) {
    return tie(a.a, a.b, a.c) < tie(b.a, b.b, b.c);
}

bool operator==(const line & a, const line & b) {
    return tie(a.a, a.b, a.c) == tie(b.a, b.b, b.c);
}

int n;
vector<point> a;

void read() {
    cin >> n;
    a.resize(n);
    for (auto &i : a)
        cin >> i.x >> i.y;
}

ll ans;

void wr(line l) {
    cout << "x * " << l.a << " + y * " << l.b << " + " << l.c << " = 0" << endl;
}

bool operator<(const point & a, const point & b) {      
    return tie(a.x, a.y) < tie(b.x, b.y);
}

void run() {
    ans = (ll) n * (n - 1) * (n - 2) / 6;
    vector<line> cnt;
    for (int i = 0; i < n; i++) {
        vector<line> have;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            line l = line(a[i], a[j]);
            have.push_back(l);
        }
        sort(all(have));
        have.resize(unique(all(have)) - have.begin());
        for (auto j : have)
            cnt.push_back(j);
    }
   /* cout << "cnt = " << endl;
    for (auto i : cnt) {
        wr(i.first);
        cout << i.first.a << " " << i.first.b << " " << i.first.c << " | " << i.second << endl;
    }*/
    sort(all(cnt));
    ll have = 1;
    for (int i = 1; i < (int)cnt.size(); i++)  {
        if (cnt[i] == cnt[i - 1]) {
            have++;
            continue;
        }
        ans -= have * (have - 1) * (have - 2) / 6;
        have = 1; 
    }
    ans -= have * (have - 1) * (have - 2) / 6;
}

void write() {
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read();
    run();
    write();
    return 0;
}