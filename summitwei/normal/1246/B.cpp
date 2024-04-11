#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 1000000007LL
#define BAD 109
#define MOD2 998244353LL
#define BAD2 41
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
ll n, k;
ll a[MN];
map<pll, ll> ree;

ll modExp(ll b, ll ex){
    ll prod = 1;
    while(ex > 0){
        if(ex % 2 == 0){
            b = (b * b) % MOD;
            ex /= 2;
        } else{
            prod = (prod*b) % MOD;
            ex--;
        }
    }
    
    return prod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> k;
    ll ans = 0;
    F0R(i, n){
        cin >> a[i];
        ll cur = 0, opp = 0, cur2 = 0, opp2 = 0;
        ll bruh = a[i];
        for(ll j=2; j*j <= bruh; ++j){
            ll cnt = 0;
            while(a[i] % j == 0){
                //cout << "found factor of " << j << "\n";
                a[i] /= j;
                ++cnt;
            }
            cnt %= k;
            if(cnt == 0) continue;
            cur += (modExp(BAD, j)*cnt);
            cur %= MOD;
            cur2 += (modExp(BAD2, j)*cnt);
            cur2 %= MOD2;
            ll o = (k-cnt)%k;
            opp += (modExp(BAD, j)*o);
            opp %= MOD;
            opp2 += (modExp(BAD2, j)*o);
            opp2 %= MOD2;
        }
        if(a[i] != 1){
            //cout << "factor of " << a[i] << "\n";
            cur += modExp(BAD, a[i]);
            cur %= MOD;
            opp += (modExp(BAD, a[i])*(k-1));
            opp %= MOD;
            cur2 += modExp(BAD2, a[i]);
            cur2 %= MOD2;
            opp2 += (modExp(BAD2, a[i])*(k-1));
            opp2 %= MOD2;
        }
        //cout << cur << " " << opp << "\n";
        ans += ree[{opp, opp2}];
        ree[{cur, cur2}]++;
    }

    cout << ans << "\n";

    return 0;
}