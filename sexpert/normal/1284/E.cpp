#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct P {
    ll x, y;
    P(ll x = 0, ll y = 0) : x(x), y(y) {}
    P operator-(const P &o) { return P(x - o.x, y - o.y); }
    int half() const { return (y < 0 || (y == 0 && x < 0)); }
    ll cross(const P &p) { return x*p.y - y*p.x; }
    bool operator<(const P &o) {
        if(half() != o.half())
            return half() < o.half();
        return cross(o) > 0;
    }
};

ll ans = 0;

int main() {
    int n;
    cin >> n;
    vector<P> ps(n);
    for(auto &p : ps)
        cin >> p.x >> p.y;
    for(int i = 0; i < n; i++) {
        vector<P> v;
        for(int j = 0; j < n; j++)
            if(i != j) v.push_back(ps[j] - ps[i]);
        sort(v.begin(), v.end());
        ll to = (ll)(n - 1)*(n - 2)*(n - 3)/6;
        for(int j = 0, k = 0; j < n - 1; j++) {
            while(k < j + n - 1 && v[j].cross(v[k%(n - 1)]) >= 0) k++;
            ll cn = k - j - 1;
            to -= (ll)cn*(cn - 1)/2;
        }
        ans += to;
    }
    cout << (ans * (n - 4))/2 << '\n';
}