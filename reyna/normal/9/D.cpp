//In the name of God
#include <iostream>
using namespace std;
const int Maxn = 36;
long long dp[Maxn][Maxn * Maxn];
long long rec(int n,int len){
    if(n > ((long long)1 << len) - 1)
        return 0;
    if(n < 0 || len < 0)
        return 0;
    if(len > n)
        return 0;
    if(dp[n][len] != -1)
        return dp[n][len];
    long long ret = 0;
    for(int i = 0; i < n;i++){
        for(int j = 0; j < len;j++){
            ret += rec(n - i - 1,len - 1) * rec(i,j);
            if(j - len + 1)
                ret += rec(n - i - 1,len - 1) * rec(i,j);
        }
    }
//  cerr << n << " " << len << " " << ret << endl;
    return dp[n][len] = ret;
}
int main(){
    int n,h;
    cin >> n >> h;
    for(int i = 0; i <= n;i++)
        for(int j = 0; j <= n;j++)
            dp[i][j] = -1;
    dp[1][1] = 1;
    dp[0][0] = 1;
    long long ans = 0;
    for(int i = h; i <= n;i++)
        ans += rec(n,i);
    cout << ans << endl;
    return 0;
}