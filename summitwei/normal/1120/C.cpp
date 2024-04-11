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
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 5005
int n, a, b;
string s;
string t; //change this

int lps[MN];
void getlps(){
    int m = t.length();
    int len = 0;
    lps[0] = 0;

    int i=1;
    while(i < m){
        if(t[i] == t[len]){
            len++;
            lps[i] = len;
            i++;
        } else{
            if(len != 0){
                len = lps[len-1];
            } else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

int kmp(int ub){ //exclusive, returns max length
    int m = t.length();
    int ans = 0;
    int i=0, j=0;
    while(i<ub){
        if(t[j] == s[i]){
            j++;
            i++;
        }
        ans = max(ans, j);

        if(j == m){
            //cout << "ree starting at " << i-j << "\n";
            //good.pb(i-j);
            j=lps[j-1];
            //return true;
        }
        
        if(i < ub && t[j] != s[i]){
            if(j != 0) j = lps[j-1];
            else i++;
        }
    }
    return ans;
}

int dp[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> a >> b >> s;

    memset(dp, 0x3f, sizeof dp);

    dp[0] = a;
    F0R(i, n){
        //cout << "cost at " << i << " is " << dp[i] << "\n";
        dp[i+1] = min(dp[i+1], dp[i]+a);
        t = s.substr(i+1);
        getlps();
        int dist = kmp(i+1);
        //cout << "longest in " << i << " is " << dist << "\n";
        FOR(j, 1, dist){
            //cout << "alt for " << i+j << " is " << dp[i]+b << "\n";
            dp[i+j] = min(dp[i+j], dp[i]+b);
        }
    }

    cout << dp[n-1] << "\n";
    
    return 0;
}