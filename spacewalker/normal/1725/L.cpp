#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for (int i = (x); i < (y); i++)
#define repl(i,x,y) for (int i = (x); i <= (y); i++)
#define INF 1e18
#define LSOne(S) (S & (-S))
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> li;
typedef vector<vector<li>> vv;

struct Fenwick {
    vector<int> v;
    int n;
    Fenwick(int num) {
        n = num;
        v.resize(n + 5);
    }
    void update(int i) {
        for (; i <= n; i += LSOne(i)) v[i]++;
    }
    int query(int i) {
        int ans = 0;
        for (; i; i -= LSOne(i)) ans += v[i];
        return ans;
    }
};

int main() {
    int n; cin >> n;
    vector<ll> pref(n + 5);
    rep(i,0,n) {
        int a; cin >> a;
        pref[i + 1] = pref[i] + a;
    }
    repl(i,1,n) {
        if (pref[i] < 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    rep(i,1,n) {
        if (pref[i] > pref[n]) {
            cout << -1 << endl;
            return 0;
        }
    }
    vector<li> v;
    repl(i,1,n) {
        v.emplace_back(pref[i], i);
        // cout << "ELEM " << pref[i] << " " << i << endl;
    }
    sort(v.rbegin(), v.rend());
    ll ans = 0;
    Fenwick ft(n);
    rep(i,0,v.size()) {
        // cout << "FEN " << v[i].first << " " << v[i].second << endl;
        ans += ft.query(v[i].second - 1);
        ft.update(v[i].second);
    }
    cout << ans << '\n';
}