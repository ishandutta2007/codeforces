#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)
 
#define MN 25
int n;
int a[MN];
bool dp[1<<MN];
vi ok[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(i, n){
        cin >> a[i];
        F0R(j, i){
            FOR(k, 0, j){
                if(a[j]+a[k] == a[i]){
                    ok[i].pb((1<<j)|(1<<k));
                    //cout << j << " " << k << " " << i << " " << ((1<<j)|(1<<k)) << "\n";
                }
            }
        }
    }

    dp[1] = true;

    FOR(i, 1, n-1){ //largest bit
        FOR(j, (1<<i)+(1<<(i-1)), (1<<(i+1))-1){
            for(auto u : ok[i]){
                //cout << "checking " << j << " " << u << "\n";
                if((j & u) == u && dp[j^(1<<i)]){
                    dp[j] = true;
                    //cout << j << " ok\n";
                    F0R(k, i){
                        dp[j&~(1<<k)] = true;
                        //cout << (j&~(1<<k)) << " found\n";
                    }
                    break;
                }
            }
        }
    }
    int res = 25;
    FOR(j, 1<<(n-1), (1<<n)-1){
        if(dp[j]){
            res = min(res, __builtin_popcount(j));
        }
    }
    if(res == 25) res = -1;
    cout << res << "\n";
    
    return 0;
}