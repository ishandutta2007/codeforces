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
#define INF 1000000000
#define MOD 998244353
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1000005
#define ML 22
int n;
int a[MN];
pii val[1<<ML]; //right, 2nd right
pii dp[1<<ML];
pii ans[1<<ML];

pii mxs(pii a, pii b){
    pii res;
    if(a.f > b.f){
        res.f = a.f;
        res.s = max(b.f, a.s);
    } else if(b.f > a.f){
        res.f = b.f;
        res.s = max(a.f, b.s);
    } else{
        res.f = a.f;
        res.s = max(a.s, b.s);
    }
    return res;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    cin >> n;
    FOR(i, 1, n){
        cin >> a[i];
        //val[1<<21-1-a[i]] = {i, val[1<<21-1-a[i]].f};
        val[a[i]] = {i, val[a[i]].f};
    }
    F0R(i, (1<<21)){
        dp[i] = val[i];
    }
    //cout << "hmm\n";
    F0R(i, 21){
        //cout << i << "\n";
        F0R(j, (1<<21)){
            if(!(j & (1<<i))){
                dp[j] = mxs(dp[j], dp[j^(1<<i)]);
            }
        }
    }
    //cout << "hmm1.5\n";
    F0R(i, (1<<21)){
        //ans[i] = dp[(1<<21)-1-i];
        ans[i] = dp[i];
        //if(ans[i] != mp(0, 0)) cout << i << " " << dp[i].f << " " << dp[i].s << "\n";
    }
    //cout << "hmm2\n";
    int fin = 0;
    FOR(i, 1, n-2){
        //cout << i << " ";
        int res = 0;
        RFOR(j, 20, 0){
            //cout << res << " ";
            if(a[i] & (1<<j)) continue;
            if(ans[res+(1<<j)].s > i){
                res += 1<<j;
            }
        }
        fin = max(fin, a[i] | res);
        //cout << "\n";
    }

    cout << fin << "\n";

    return 0;
}