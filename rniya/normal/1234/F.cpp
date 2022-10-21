#include <bits/stdc++.h>
using namespace std;

int dp[1<<20];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S; cin >> S;
    int n=S.size();
    vector<int> cand;
    for (int i=0;i<n;++i){
        int now=0,cnt=0;
        for (int j=i;j<n;++j){
            if (now&1<<(S[j]-'a')) break;
            now|=1<<(S[j]-'a'); cand.emplace_back(now);
            dp[((1<<20)-1)^now]=++cnt;
        }
    }
    for (int mask=(1<<20)-1;mask>=0;--mask)
        for (int j=0;j<20;++j) if (!(mask&1<<j))
            dp[mask]=max(dp[mask],dp[mask|1<<j]);
    int ans=0;
    for (int mask:cand) ans=max(ans,__builtin_popcount(mask)+dp[mask]);
    cout << ans << '\n';
}