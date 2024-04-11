#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    ll x[100002], y[100002];
    vector<ll> rl[100002], ud[100002];
    for(int i = 0; i < k; i++){
        scanf("%lld %lld", &x[i], &y[i]);
        x[i]--;
        y[i]--;
        rl[x[i]].push_back(y[i]);
        ud[y[i]].push_back(x[i]);
    }
    ll nl = -1, nr = m, nu = 0, nd = n;
    ll d = 0;
    for(int i = 0; i < n; i++){
        sort(rl[i].begin(), rl[i].end());
    }
    for(int i = 0; i < m; i++){
        sort(ud[i].begin(), ud[i].end());
    }
    while(true){
        ll rs, ds, ls, us;
        if(upper_bound(rl[nu].begin(), rl[nu].end(), nl) != rl[nu].end()){
            rs = min(*upper_bound(rl[nu].begin(), rl[nu].end(), nl), nr);
        }
        else rs = nr;
        if(rs - 1 == nl) break;
        nr = rs - 1;
        d += nr - nl;
        if(upper_bound(ud[nr].begin(), ud[nr].end(), nu) != ud[nr].end()){
            ds = min(*upper_bound(ud[nr].begin(), ud[nr].end(), nu), nd);
        }
        else ds = nd;
        if(ds - 1 == nu) break;
        nd = ds - 1;
        d += nd - nu;
        if(upper_bound(rl[nd].begin(), rl[nd].end(), nr) != rl[nd].begin()){
            ls = max(*(upper_bound(rl[nd].begin(), rl[nd].end(), nr) - 1), nl);
        }
        else ls = nl;
        if(nr - 1 == ls) break;
        nl = ls + 1;
        d += nr - nl;
        if(upper_bound(ud[nl].begin(), ud[nl].end(), nd) != ud[nl].begin()){
            us = max(*(upper_bound(ud[nl].begin(), ud[nl].end(), nd) - 1), nu);
        }
        else us = nu;
        if(nd - 1 == us) break;
        nu = us + 1;
        d += nd - nu;
    }
    if(n * m - d == k) cout << "Yes" << endl;
    else cout << "No" << endl;
}