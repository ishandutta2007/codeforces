#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 1000000 + 10;
const int MOD = 1e9+7;
typedef long long LL;
int n,a[N];
int dp[N];

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    dp[0]=1;
    for(int i=1;i<=n;i++){
        vector<int> v;
        for(int x=1;x*x<=a[i];x++){
            if(a[i]%x==0) {
                v.push_back(x);
                if(x*x!=a[i])v.push_back(a[i]/x);
            }    
        }
        sort(v.begin(),v.end());
        for(int x=v.size()-1;x>=0;x--){
            (dp[v[x]] += dp[v[x]-1]) %= MOD;
        }
    }
    int ans=0;
    for(int i=1;i<=1000000;i++)ans=(ans+dp[i])%MOD;
    cout<<ans<<endl;
}