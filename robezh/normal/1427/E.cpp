#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pll> vpl;


const int B = 60;
mt19937 rng(2333);
map<ll, int> mp;
vector<string> res;

struct Basis {
    int sz = 0;
    ll bas[B];

    bool add(ll x) {
        if(x == 0) return false;

        vpl v;
        for(int i = 0; i < sz; i++) {
            if((x ^ bas[i]) < x) {
                v.push_back({x, bas[i]});
                x ^= bas[i];
            }
            if(x == 0) return false;
        }
        bas[sz++] = x;
        for(int i = sz - 2; i >= 0; i--) {
            if(bas[i] < bas[i+1]) swap(bas[i], bas[i+1]);
        }
        for(auto &p : v) {
            if(!p.first || !p.second) continue;
            res.push_back(to_string(p.first) + " ^ " + to_string(p.second));
//            cout << p.first << " ^ " << p.second<< '\n';
            assert(mp[p.first]);
            assert(mp[p.second]);
            mp[(p.first ^ p.second)] = 1;

        }
        return true;
    }


    ll getsum() {
        while(true) {
            vpl v;
            ll a = 0;
            for(int j = 0; j < sz; j++) {
                if(rng() % 2 == 0) {
                    v.push_back({a, bas[j]});
                    a ^= bas[j];
                }
            }
            ll b = 0;
            for(int j = 0; j < sz; j++) {
                if(rng() % 2 == 0) {
                    v.push_back({b, bas[j]});
                    b ^= bas[j];
                }
            }
            if(a && b && a + b < (1LL << 60)) {
                for(auto &p : v) {
                    if(!p.first || !p.second) continue;
                    res.push_back(to_string(p.first) + " ^ " + to_string(p.second));
                    assert(mp[p.first]);
                    assert(mp[p.second]);
                    mp[(p.first ^ p.second)] = 1;
                }
                res.push_back(to_string(a) + " + " + to_string(b));
                assert(mp[a]);
                assert(mp[b]);
                mp[a + b] = 1;
                return a + b;
            }
        }
    }
}basis;



int main() {
    int x;
    cin >> x;
    while(true) {
        Basis b;
        mp[x] = 1;
        b.add(x);
        int cnt = 0;
        while(b.sz < 60) {
//        cnt++;
            b.add(b.getsum());
        }
        if(res.size() <= (int)1e5) {
            cout << sz(res) << '\n';
            for(string &s : res) cout << s << '\n';
            return 0;
        }
    }
//    cout << cnt << endl;


}