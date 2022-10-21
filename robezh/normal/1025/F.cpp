#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
typedef long long ll;
typedef long double ld;
const ld EPS = 1e-15;
const ld PI = acos(-1.0);

struct P {
    ll x, y;
    P(ll _x = 0, ll _y = 0){x = _x, y = _y;}
    ll operator * (const P & he) const {
        return x * he.y - y * he.x;
    }
    bool operator < (const P & he) const {
        return *this * he > 0;
    }
    P operator - (const P & he) const {
        return P{x - he.x, y - he.y};
    }
    P operator - () const {
        return P{-x, -y};
    }
};


int n;
P p[N];
vector<P> x;

ll C(ll k) {
    return k * (k - 1) / 2;
}

bool ccw(P p, P q, P r){
    return (q - p) * (r - q) >= 0;
}

int main() {
    ll res = 0;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;

    for(int i = 0; i < n; i++) {
        x.clear();
        ll nx = p[i].x, ny = p[i].y;

        vector<P> left, right;
        for(int j = 0; j < n; j++){
            if(i != j){
                auto pr = p[j] - p[i];
                if(pr.x > 0 || (pr.x == 0 && pr.y > 0)) right.push_back(pr);
                else left.push_back(pr);
            };
        }
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        x.insert(x.end(), left.begin(), left.end());
        x.insert(x.end(), right.begin(), right.end());
        int r = 0;
        for(int j = 0; j < n - 1; j++){
            while(r - j < n - 1 && ccw(x[j], x[r % (n - 1)], {0, 0})) {
                r++;
            }
            res += C(r - j - 1) * C(n - 1 - (r - j));
        }
    }
    cout << res / 2 << endl;
}