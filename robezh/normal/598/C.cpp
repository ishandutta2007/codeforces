#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ld PI = 3.1415926535897;

struct P {
    ll x, y;
    ld arc;
    P(ll _x = 0, ll _y = 0){x = _x, y = _y; arc = atan2((ld)x, (ld)y);}
    ll operator * (const P & he) const {
        return x * he.y - y * he.x;
    }
    bool operator < (const P & he) const {
        return arc < he.arc;
    }
    P operator - (const P & he) const {
        return P{x - he.x, y - he.y};
    }
    P operator - () const {
        return P{-x, -y};
    }
};

typedef pair<P, int> Pi;

int n;

int main() {
    cin >> n;
    vector<Pi> pts;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pts.push_back({{x, y}, i});
    }
    sort(pts.begin(), pts.end());
    pts.push_back(pts[0]);
    pts.back().first.arc += 2 * PI;

    ld res = 100000;
    int x, y;


    for(int i = 0; i < n; i++) {
        ld ans = abs(pts[i].first.arc - pts[i+1].first.arc);
        if(ans < res) {
            res = ans;
            x = pts[i].second + 1;
            y = pts[i+1].second + 1;
        }
    }
//    cout << res << endl;
    cout << x << " " << y << endl;

}