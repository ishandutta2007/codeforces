#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef pair<ll, ll> ii;

int n, m;
ll a, d;
deque<ii> Q;

inline ll endtime(ii p) {
    return p.first + a * (p.second - 1LL);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> a >> d;

    ll t;
    ll pref = 0;
    for(int i = 0 ; i < m ; i++) {
        cin >> t;
        if(t - t % a > pref) {
            ll first = pref - pref % a + a;
            ll last = min(ll(n) * a, (t - t % a) );
            if(last >= first)
                Q.push_back({(first), ((last) - (first)) / a + 1LL});
        }
        Q.push_back({t, 1});
        pref = t;
    }

    t = ll(n) * a;
    if(t - t % a > pref) {
        Q.push_back({(pref - pref % a + a), ((t - t % a) - (pref - pref % a + a)) / a + 1LL});
    }

    ll res = 0;
    while(!Q.empty()) {
        ll pocz = Q.front().first;


       // cout << Q.front().first << " " << Q.front().second << endl;
        if(endtime(Q.front()) > pocz + ll(2) * d) {
            ii p = Q.front();
            Q.pop_front();
            ll ile_wchodzi = d / a + ll(1);
            ll we_take = p.second - p.second % ile_wchodzi;

            if(we_take <= ile_wchodzi) {
                Q.push_front(p);
                goto nekst;
            }

            if(we_take == p.second) {
                we_take -= ile_wchodzi;
            }

            res += we_take / ile_wchodzi;
            Q.push_front({p.first + (we_take) * a, p.second - we_take});
            if(Q.front().second == 0)
                Q.pop_front();
         //   cout << res << endl;
            continue;
        }

        nekst:

        res++;
        while(!Q.empty() && endtime(Q.front()) <= pocz + d)
            Q.pop_front();

        if(!Q.empty() && Q.front().first <= pocz + d) {
            ii p = Q.front();
            Q.pop_front();

            ll we_take = (pocz + d - p.first) / a + ll(1);
            Q.push_front({p.first + (we_take) * a, p.second - we_take});
            if(Q.front().second == 0)
                Q.pop_front();
        }

      //  cout << res << endl;
    }

    cout << res << endl;

    return 0;
}