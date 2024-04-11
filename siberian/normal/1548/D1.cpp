#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

#define int ll

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// int get(int l, int r) {
//     return (ull)rnd() % (r - l + 1) + l;
// }

// template<typename T1, typename T2> 
// inline void chkmin(T1& x, const T2& y) {
//     if (y < x) x = y;
// }

// template<typename T1, typename T2>
// inline void chkmax(T1& x, const T2& y) {
//     if (x < y) x = y;
// }

// struct Point{
//     int x, y;
//     Point() : x(), y() {}
//     Point(int _x, int _y) : x(_x), y(_y) {}
// };

// Point operator-(const Point& a, const Point& b) {
//     return Point(a.x - b.x, a.y - b.y);
// }

// int sign(ll x) {
//     if (x < 0) return -1;
//     if (x > 0) return 1;
//     return 0;
// }

// ll operator^(const Point& a, const Point& b) {
//     return (ll)a.x * b.y - (ll)a.y * b.x;
// }

// ll operator*(const Point& a, const Point& b) {
//     return (ll)a.x * b.x + (ll)a.y * b.y;
// }

// #define Vec Point

// bool isIn(const Point& a, const Point& b, const Point& c, const Point& x) {
//     Vec v1 = b - a;
//     Vec v2 = c - a;
//     Vec v3 = x - a;
//     if (sign(v1 ^ v3) != sign(v3 ^ v2)) return false;
//     v1 = a - b;
//     v2 = c - b;
//     v3 = x - b;
//     if (sign(v1 ^ v3) != sign(v3 ^ v2)) return false;
//     return true;
// }

// bool check(const Point& a, const Point& b, const Point& c) {
//     Vec v1 = b - a;
//     Vec v2 = c - a;
//     Vec v3 = a - c;
//     return sign(v1 * v2) == 0 || sign(v1 * v3) == 0 || sign(v2 * v3) == 0;
// }

// const int C = 10;

// bool stupidCheck(const Point& a, const Point& b, const Point& c) {
//     int ans = 0;
//     for (int x = 0; x < 2 * C; ++x) {
//         for (int y = 0; y < 2 * C; ++y) {
//             ans += isIn(a, b, c, Point(x, y));
//         }
//     }
//     return ans & 1;
// }

// Point get() {
//     return Point(get(1, C) * 2, get(1, C) * 2);
// }

// int gcd(int a, int b) {
//     while (b) {
//         a %= b;
//         swap(a, b);
//     }
//     return a;
// }

// int calc(const Vec& v) {
//     v.x = abs(v.x);
//     v.y = abs(v.y);
//     int g = gcd(v.x, v.y);
//     return g % 2;
// }


signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    // while (true) {
    int n;
    cin >> n;
    int a[4][4];
    for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) a[i][j] = 0;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        x %= 4;
        y %= 4;
        a[x][y]++;
    }
    ll ans = (ll)n * (n - 1) * (n - 2) / 6 - (ll)a[0][0] * a[0][2] * a[2][0] - (ll)a[2][2] * a[0][2] * a[2][0] - (ll)a[0][0] * a[2][0] * a[2][2] - (ll)a[0][0] * a[0][2] * a[2][2];
    cout << ans << endl;
    return 0;
}