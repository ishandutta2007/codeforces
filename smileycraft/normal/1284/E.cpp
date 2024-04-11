
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpll = vector<pll>;
using vvll = vector<vll>;

template <typename N = ld>
struct point{
    N x, y;

    point(N x_ = 0, N y_ = 0) : x(x_), y(y_) {}

    point<N> operator- (point<N> p) {return {x - p.x, y - p.y};}
    N operator* (point<N> p) {return x * p.x + y * p.y;} // inner product
    N operator^ (point<N> p) {return x * p.y - y * p.x;} // cross product

    N length_squared() {return x * x + y * y;}
    N distance_squared(point<N> p) {return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);}
    N length() {return sqrtl(length_squared());}
    N distance(point<N> p) {return sqrtl(distance_squared(p));}
    point<N> &normalize() {return *this /= length();}
};

template <typename N = ld>
struct line{
    point<N> p, q;

    line(point<N> p_ = {0, 0}, point<N> q_ = {0, 0}) : p(p_), q(q_) {}

    point<N> dir() {return q - p;}
    N length() {return p.distance(q);}
    N length_squared() {return p.distance_squared(q);}

    point<N> operator() (N n) {return p + n * dir();}
};

ll choose4(ll n) {return n * (n - 1) * (n - 2) * (n - 3) / 24;}

int main(){
    ll n;
    cin >> n;
    vector<point<ll>> ps(n);
    for (ll i = 0; i < n; ++i) cin >> ps[i].x >> ps[i].y;
    ll total = 0;
    for (ll i = 0; i < n; ++i){
        point<ll> p = ps[i];
        vll js(n);
        for (ll j = 0; j < n; ++j) js[j] = j;
        js[i] = n - 1;
        js.pop_back();
        auto comp = [&](ll j1, ll j2){
            point<ll> p1 = ps[j1] - p, p2 = ps[j2] - p;
            bool b1 = p1.y == 0 ? p1.x > 0 : p1.y > 0, b2 = p2.y == 0 ? p2.x > 0 : p2.y > 0;
            if (b1 != b2) return b1;
            return (p1 ^ p2) > 0;
        };
        sort(js.begin(), js.end(), comp);
        total += choose4(n - 1);
        ll j1 = 0, j2 = 0;
        while (true){
            //cout << i << ' ' << j1 << ' ' << j2 << endl;
            while (((ps[js[j1 % (n - 1)]] - p) ^ (ps[js[(j2 + 1) % (n - 1)]] - p)) > 0) ++j2;
            //cout << i << ' ' << j1 << ' ' << j2 << endl;
            if (j1 == 0 && j2 == n - 2){
                total -= choose4(n - 1);
                break;
            }
            if (j1 > 0) total -= choose4(j2 - j1 + 1);
            while (((ps[js[j1 % (n - 1)]] - p) ^ (ps[js[(j2 + 1) % (n - 1)]] - p)) < 0) ++j1;
            if (j1 > j2){
                total -= choose4(n - 1);
                break;
            }
            if (j1 <= n - 1) total += choose4(j2 - j1 + 1);
            else break;
        }
        //cout << total << endl;
    }
    cout << total << endl;
    return 0;
}