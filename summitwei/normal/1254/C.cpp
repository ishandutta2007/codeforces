#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<pll> vpll;
#define INF 1000000000000000000LL
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1005
int n;

ll q1(int i, int j, int k){
    cout << "1 " << i << " " << j << " " << k << endl;
    cout.flush();
    ll resp;
    cin >> resp;
    return resp;
}
ll q2(int i, int j, int k){
    cout << "2 " << i << " " << j << " " << k << endl;
    cout.flush();
    ll resp;
    cin >> resp;
    return resp;
}
ll ar[MN];
ll od[MN];
vpll lft;
vpll rt;

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    cin >> n;
    int lm = 2;
    FOR(i, 3, n){
        if(q2(1, lm, i) == 1){
            lm = i;
        }
    }
    int mx = 2;
    FOR(i, 2, n){
        if(i == lm) continue;
        ar[i] = q1(1, lm, i);
        if(ar[i] > ar[mx]) mx = i;
    }
    FOR(i, 2, n){
        if(i == mx) continue;
        ll res = q2(1, mx, i);
        if(res == 1){
            lft.pb(mp(ar[i], (ll)i));
        } else{
            rt.pb(mp(ar[i], (ll)i));
        }
    }
    sort(lft.begin(), lft.end());
    sort(rt.begin(), rt.end());

    cout << "0 1 ";
    F0R(i, rt.size()){
        cout << rt[i].s << " ";
    }
    cout << mx << " ";
    RFOR(i, lft.size()-1, 0){
        cout << lft[i].s << " ";
    }
    cout << endl;
    cout.flush();
    return 0;
}