#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (ll i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 30
ll rand2(){
    return rand()*32768+rand();
}

ll n;
ll que(ll type, ll i){
    if(type == 0){
        cout << "? " << i << endl;
        cout.flush();
    } else{
        cout << "> " << i << endl;
        cout.flush();
    }

    ll resp;
    cin >> resp;
    if(resp == -1) exit(0);
    return resp;
}

set<ll> used;
ll resps[MN];
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    srand(time(NULL));

    cin >> n;
    if(n <= 60){
        ll mn = INF, mx = 0;
        FOR(i, 1, n){
            ll resp = que(0, i);
            mn = min(mn, resp);
            mx = max(mx, resp);
        }

        cout << "! " << mn << " " << (mx-mn)/(n-1) << endl;
        return 0;
    }

    ll l = 0;
    ll r = INF;
    while(l+1 < r){
        ll mid = (l+r)/2;
        ll resp = que(1, mid);
        if(resp == 1){
            l = mid;
        } else{
            r = mid;
        }
    }

    ll tims = min(n, 25LL);
    F0R(i, tims){
        ll rn = 1+rand2()%n;
        while(used.count(rn)){
            rn = 1+rand2()%n;
        }
        used.insert(rn);
        ll resp = que(0, rn);
        resps[i] = resp;
    }

    /*F0R(i, tims){
        resps[i] = que(0, i);
    }*/

    sort(resps, resps+tims);
    ll cur = resps[1]-resps[0];
    F0R(i, tims-1){
        ll diff = resps[i+1] - resps[i];
        cur = __gcd(cur, diff);
    }

    //cout << r << "\n";
    cout << "! " << r-cur*(n-1) << " " << cur << endl;
    cout.flush();
    return 0;
}