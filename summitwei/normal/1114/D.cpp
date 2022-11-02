#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (ll i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 5005
int n;
int c[MN];

int l[MN];
int r[MN];

int dp[MN][MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    F0R(i, n){
        cin >> c[i];
    }

    F0R(i, n){
        int j = i;
        while(j >= 1 && c[j-1]==c[i]) j--;
        l[i] = j;
        j = i;
        while(j < n-1 && c[j+1] == c[i]) j++;
        r[i] = j;
    }

    memset(dp, 0x3f, sizeof dp);
    F0R(i, n){
        if(l[i] == i){
            dp[i][r[i]] = 0;
        }
    }

    /*F0R(i, n){
        F0R(j, n){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/

    F0R(dist, n-1){
        F0R(i, n-dist){
            int j = i+dist;
            if(dp[i][j] == INF) continue;
            
            if(i != 0 && j != n-1 && c[i-1] == c[j+1]){
                dp[l[i-1]][r[j+1]] = min(dp[l[i-1]][r[j+1]], dp[i][j]+1);
            }
            if(i != 0){
                dp[l[i-1]][j] = min(dp[l[i-1]][j], dp[i][j]+1);
            }
            if(j != n-1){
                dp[i][r[j+1]]=min(dp[i][r[j+1]], dp[i][j]+1);
            }
        }
    }

    cout << dp[0][n-1] << "\n";
    
    return 0;
}