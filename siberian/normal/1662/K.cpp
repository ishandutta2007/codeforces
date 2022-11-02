#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
// using ld = long double;
using ld = double;

const ld EPS = 1e-6;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

ld sq(ld x) {
    return x * x;
}

struct vec {
    ld x, y;
};

vec operator-(const vec &a, const vec &b) {
    return {a.x - b.x, a.y - b.y};
}

ld cross(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}

ld len(vec a) {
    return sqrt(sq(a.x) + sq(a.y));
}

ld asd(vec a, vec b)
{
    return a.x *b.x+a.y*b.y;
}
const ld PI = acos(-1.0);
ld getang(vec a, vec b, vec c)
{
    vec v1 = b-a;
    vec v2=  c-a;
    return abs(atan2(cross(v1,v2), asd(v1,v2)));
}

ld getT(vec a, vec b, vec c) {
    ld A = len(b - c);
    ld B = len(a - c);
    ld C = len(a - b);
    if(getang(a,b,c) >PI*2/3|| getang(b,a,c)>PI*2/3||getang(c,a,b)>PI*2/3) 
    {
        return min({A+B,B+C,A+C});
    }
    ld cc = cross(c - a, b - a);
    if (abs(cc) < EPS) {
        return max({A, B, C});
    }
    ld R = A * B * C / (2 * cc);
    if (R < 0)
        R = -R;
    ld S2 = (sq(A) + sq(B) + sq(C)) / 2 + sqrt(3) * abs(cc);
    
    return min({sqrt(S2), A + B, B + C, A + C});
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    vec a, b, c;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    vector<vec> fcur = {
        {(a.x + b.x + c.x) / 3, (a.y + b.y + c.y) / 3},
        a,
        b,
        c
    };
    ld temp = 0.9999;
    ld cur_eps = max(max({a.x, b.x, c.x}) - min({a.x, b.x, c.x}), max({a.y, b.y, c.y}) - min({a.y, b.y, c.y})) / 5000;
    ld sum_eps = 0;
    vector<int> dx = {-1, -1, -1, 0, 1, 1, 1, 0};
    vector<int> dy = {-1, 0, 1, 1, 1, 0, -1, -1};
    while (clock() < CLOCKS_PER_SEC * 3.9) {
        cur_eps *= temp;
        sum_eps += cur_eps;
        for (auto& cur : fcur) {
            vector<vec> arr;
            for (int it = 0; it < dx.size(); ++it) {
                int sum = abs(dx[it]) + abs(dy[it]);
                arr.push_back({
                    cur.x + cur_eps * dx[it] / sum,
                    cur.y + cur_eps * dy[it] / sum
                });
            }
            vector<ld> d;
            for (auto el : arr) {
                d.push_back(max({getT(a, b, el), getT(a, c, el), getT(b, c, el)}));
            }
            int i = min_element(d.begin(), d.end()) - d.begin();
            cur = arr[i];
        }
    }
    cerr << "sum_eps = " << sum_eps << endl;
    cerr << "final_eps = " << cur_eps << endl;
    ld ans = 1e40;
    for (auto& cur : fcur) {
        chkmin(ans, max({getT(a, b, cur), getT(a, c, cur), getT(b, c, cur)}));
    }
    
    cout << ans << endl;
    return 0;
}