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
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 300005
int n;
int a[MN];
//ll dp[MN][2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 1, n){
        cin >> a[i];
    }
    //0 = bot not used
    /*if(a[1]%2==0){
        dp[1][0] = a[1]/2-1; dp[1][1] = a[1]/2;
    } else{
        dp[1][0] = a[1]/2; dp[1][1] = -INF;
    }
    FOR(i, 2, n){
        if(a[i]%2==0){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1])+a[i]/2-1;
            dp[i][1] = max(dp[i-1][0]+dp[i-1][]);
        }
    }*/
    ll sm = 0;
    int cnt = 0;
    FOR(i, 1, n){
        sm += a[i]/2;
        if(a[i]%2==1){
            if(i % 2 == 0){
                ++cnt;
                if(cnt <= 0) ++sm;
            } else{
                --cnt;
                if(cnt >= 0) ++sm;
            }
            /*if(mr != 0 && mr % 2 != i % 2){
                ++sm;
                mr = 0;
            } else{
                mr = i;
            }*/
        }
    }
    
    cout << sm << "\n";

    return 0;
}