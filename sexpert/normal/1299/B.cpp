#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct P {
    ll x, y;
    P(ll _x = 0, ll _y = 0) : x(_x), y(_y) {}
    P operator+(const P &p) { return P(x + p.x, y + p.y); }
    P operator-(const P &p) { return P(x - p.x, y - p.y); }
    bool operator<(const P &p) const {
        return tie(x, y) < tie(p.x, p.y);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<P> v(n);
    set<P> all;
    for(auto &p : v) {
        cin >> p.x >> p.y;
        all.insert(p);
    }
    if(n % 2) {
        cout << "No\n";
        return 0;
    }
    P su;
    for(auto p : v)
        su = su + p;
    ll k = n / 2;
    if(su.x % k || su.y % k) {
        cout << "No\n";
        return 0;
    }
    P ce(su.x / k, su.y / k);
    for(auto p : v) {
        if(!all.count(ce - p)) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}