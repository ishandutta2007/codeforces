#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 5005

ll factorial(ll x){
    ll ans = 1;
    for(ll i=1; i<=x; i++){
        ans = (ans*i)%MOD;
    }

    return ans;
}

pair<ll, ll> euclid(ll a, ll b){ //finds {x, y} s.t. ax+by=gcd(a, b);
    if(b == 0){
        return {1, 0};
    }

    pair<ll, ll> ans = euclid(b, a%b);
    ll x = ans.first, y = ans.second;
    return {y, x-y*(a/b)};
}

ll modInv(ll num){
    pair<ll, ll> bez = euclid(num, MOD);
    
    if(bez.first < 0) bez.first += MOD;

    return bez.first;
}

ll choose(ll x, ll y){
    ll top = factorial(x);
    ll bot1 = factorial(y);
    ll bot2 = factorial(x-y);
    ll bot = (bot1*bot2) % MOD;
    return (top * modInv(bot)) % MOD;
}

int n;
string s;

int dp[MAX_N][MAX_N];
bool used[26];

int lastApp[26];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;
    string delet(1, s[0]);
    for(int i=1; i<n; i++){
        if(s[i] != s[i-1]){
            delet += s[i];
        }
    }
    //cout << delet << "\n";

    memset(lastApp, -1, sizeof lastApp);

    int size = delet.length();

    //dp[0][0] = 1;
    lastApp[delet[0]-'a'] = 0;
    for(int i=0; i<size; i++){
        dp[i][1] = 1;
    }

    for(int i=1; i<size; i++){
        lastApp[delet[i]-'a']=i;

        for(int j=2; j<=i+1; j++){
            int sum = 0;
            /*for(int k=i-1; k>=0; k--){
                if(used[delet[k]-'a'] && j!=1) continue;
                if(delet[i] == delet[k] && j!=1) continue;

                sum = (sum+dp[k][j-1])%MOD;
                used[delet[k]-'a'] = true;
            }*/

            for(int k=0; k<26; k++){
                if((delet[i]-'a' == k) || lastApp[k] == -1) continue;
                
                sum = (sum+dp[lastApp[k]][j-1]) % MOD;
            }

            dp[i][j] = sum;
        }
    }

    /*for(int i=0; i<size; i++){
        for(int j=1; j<=size; j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/

    ll finalSum = 0;
    for(int i=1; i<=size; i++){
        //memset(used, false, sizeof used);

        ll total = 0;
        /*for(int j=size-1; j>=0; j--){
            if(used[delet[j]-'a']) continue;

            total = (total + dp[j][i]) % MOD;
            used[delet[j]-'a'] = true;
        }*/
        for(int j=0; j<26; j++){
            if(lastApp[j] == -1) continue;

            total = (total+dp[lastApp[j]][i]) % MOD;
        }

        finalSum = (finalSum + (choose(n-1, i-1)*total)) % MOD;
        //cout << n-1 << " choose " << i-1 << " is " << choose(n-1, i-1) << " and it appears " << total << " times\n";
    }

    cout << finalSum << "\n";
    
    return 0;
}