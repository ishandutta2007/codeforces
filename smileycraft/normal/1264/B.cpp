
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpll = vector<pll>;
using vvll = vector<vll>;

int main(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b < a){
        if (c == 0 && d == 0 && a == b + 1){
            cout << "YES" << endl << 0;
            for (ll i = 0; i < b; ++i) cout << " 1 0";
            cout << endl;
        }
        else cout << "NO" << endl;
    }
    else if (c < d){
        if (a == 0 && b == 0 && d == c + 1){
            cout << "YES" << endl << 3;
            for (ll i = 0; i < c; ++i) cout << " 2 3";
            cout << endl;
        }
        else cout << "NO" << endl;
    }
    else if (abs((b - a) - (c - d)) <= 1){
        vll v;
        if (b - a == c - d + 1) v.push_back(1);
        for (ll i = 0; i < a; ++i){
            v.push_back(0);
            v.push_back(1);
        }
        for (ll i = 0; i < min(b - a, c - d); ++i){
            v.push_back(2);
            v.push_back(1);
        }
        for (ll i = 0; i < d; ++i){
            v.push_back(2);
            v.push_back(3);
        }
        if (c - d == b - a + 1) v.push_back(2);
        cout << "YES" << endl << v[0];
        for (ll i = 1; i < v.size(); ++i) cout << ' ' << v[i];
        cout << endl;
    }
    else cout << "NO" << endl;
    return 0;
}