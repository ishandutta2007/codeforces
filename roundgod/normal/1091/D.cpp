#include<bits/stdc++.h>
#define maxn 5505050

using namespace std;
typedef long long ll;
const ll M=998244353;
ll dp[maxn],f[maxn],n;

int main(){
    cin >> n;
    dp[1]=1; f[0]=1;
    for (int i=1;i<=n;i++) f[i]=f[i-1]*i%M;
    for (int i=2;i<=n;i++) dp[i]=(dp[i-1]+f[i-1]-1)*i%M;
    cout << dp[n] << endl;
    return 0;
}