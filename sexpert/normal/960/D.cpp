#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll lshift[63], pshift[63];

ll label(ll x) {
    ll sz = (1LL << 61);
    while((sz & x) == 0)
        sz /= 2;
    int lev = __builtin_ctzll(sz);
    x = (x - lshift[lev] - pshift[lev]) % sz;
    if(x < 0)
        x += sz;
    x += sz;
    return x;
}

void qry(ll x) {
    ll sz = (1LL << 61);
    while((sz & x) == 0)
        sz /= 2;
    int lev = __builtin_ctzll(sz);
    x = (x + lshift[lev] + pshift[lev]) % sz;
    if(x < 0)
        x += sz;
    x += sz;
    vector<ll> ans;
    while(x > 1) {
        ans.push_back(label(x));
        ll y = x / 2;
        sz /= 2;
        lev--;
        y = (y + pshift[lev]) % sz;
        if(y < 0)
            y += sz;
        y += sz;
        x = y;
    }
    ans.push_back(1);
    for(auto a : ans)
        cout << a << " ";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--) {
        ll t, x, k;
        cin >> t >> x;
        if(t < 3) {
            cin >> k;
            ll sz = (1LL << 61);
            while((sz & x) == 0)
                sz /= 2;
            int lev = __builtin_ctzll(sz);
            if(t == 1) {
                lshift[lev] = (lshift[lev] + k) % sz;
                if(lshift[lev] < 0)
                    lshift[lev] += sz;
            }
            else {
                pshift[lev] = (pshift[lev] + k) % sz;
                if(pshift[lev] < 0)
                    pshift[lev] += sz;
            }
        }
        else
            qry(x);
    }
}