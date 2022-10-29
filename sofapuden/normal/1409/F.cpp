#include<bits/stdc++.h>

using namespace std;

int dp[205][205][205], n, k;
string s1, s2;

int rec(int step, int am, int ite){
    if(dp[step][am][ite] != -1)return dp[step][am][ite];
    if(step >= n)return 0;
    if(s1[step] == s2[0])dp[step][am][ite] = rec(step+1,am+1,ite);
    else if(s1[step] == s2[1])dp[step][am][ite] = rec(step+1,am,ite)+am;
    else dp[step][am][ite] = rec(step+1,am,ite);
    if(ite >= k)return dp[step][am][ite];
    dp[step][am][ite] = max({dp[step][am][ite], rec(step+1,am+1,ite+1),rec(step+1,am,ite+1)+am});
    return dp[step][am][ite];
}

int main(){
    cin >> n >> k >> s1 >> s2;
    memset(dp,-1,sizeof dp);
    if(s2[0] == s2[1]){
        int ans = 0;
        for(int i = 0; i < n; ++i){
            ans+=(s2[0] == s1[i]);
        }
        ans = min(n,ans+k);
        cout << ((ans*(ans-1))>>1) << "\n";
        return 0;
    }
    cout << rec(0,0,0);
}