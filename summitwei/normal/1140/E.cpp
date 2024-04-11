#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
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

#define MN 200005
ll n, k;
ll a[MN];
ll dp[MN][2]; //(!= r, == r)
bool ch[MN];

ll getDP(int l, int r, int nums){
    if(a[l] == -1){
        dp[0][0] = k-1;
        dp[0][1] = 1;
    } else if(r <= n && a[l] == a[r]){
        dp[0][1] = 1;
        dp[0][0] = 0;
    } else{
        dp[0][0] = 1;
        dp[0][1] = 0;
    }

    F0R(i, nums-1){
        //dp[i+1][0] = 0; dp[i+1][1] = 0;
        dp[i+1][0] = ((dp[i][0]*(k-2))%MOD + dp[i][1]*(k-1))%MOD;
        dp[i+1][1] = dp[i][0];
    }

    if(r >= n){
        //cout << l << " " << r << " " << dp[nums-2][0]+dp[nums-2][1] << "\n";
        return dp[nums-2][0]+dp[nums-2][1];
    } else{
        //cout << l << " " << r << " " << dp[nums-1][1] << "\n";
        return dp[nums-1][1];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    F0R(i, n){
        cin >> a[i];
    }
    ll cur = 1;
    F0R(i, n){
        if(ch[i]) continue;
        ch[i] = true;

        int j = i+2;
        while(j < n && a[j] == -1){
            ch[j] = true;
            j += 2;
        }

        int nums = (j-i)/2+1;
        cur *= getDP(i, j, nums);
        cur %= MOD;
    }

    cout << cur << "\n";
    
    return 0;
}