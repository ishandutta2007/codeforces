    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    typedef pair<ll, ll> ii;
     
    map<char, ii> t;
     
    int main() {
        t['U'] = {0, 1};
        t['D'] = {0, -1};
        t['L'] = {-1, 0};
        t['R'] = {1, 0};
        ll x1, y1, x2, y2;
        int n;
        string s;
        cin >> x1 >> y1 >> x2 >> y2 >> n >> s;
        vector<ii> v(n);
        ii acc = {0, 0};
        for(int i = 0; i < n; i++) {
            v[i] = {x1 + acc.first, y1 + acc.second};
            ii mv = t[s[i]];
            acc.first += mv.first;
            acc.second += mv.second;
        }
        //cout << acc.first << " " << acc.second << endl;
        ll ans = 1e18;
        for(int i = 0; i < n; i++) {
            ll lo = 0, hi = 1e10;
            while(lo < hi) {
                ll mi = (lo + hi)/2ll;
                ii pos = v[i];
                pos.first += mi*acc.first;
                pos.second += mi*acc.second;
                //cout << pos.first << " " << pos.second << " " << abs(x2 - pos.first) + abs(y2 - pos.second) << " " << mi*n + i << endl;
                if(abs(x2 - pos.first) + abs(y2 - pos.second) <= mi*n + i)
                    hi = mi;
                else
                    lo = mi + 1;
            }
            if(hi < 1e10)
                ans = min(ans, lo*n + i);
        }
        cout << (ans == 1e18 ? -1 : ans) << endl;
    }