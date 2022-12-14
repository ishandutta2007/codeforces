#include<bits/stdc++.h>
using namespace std;
long long dp[(1<<20)];
int adj[22][22];
int contrib[21][(1<<20)];
int cost[(1<<20)];
short int msb[(1<<20)];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    string s;
    cin>>n>>m>>s;
    for (int i=1;i<n;i++) {
        adj[s[i]-'a'][s[i-1]-'a']++;
        adj[s[i-1]-'a'][s[i]-'a']++;
    }
    int tot=(1<<m);
    for (int i=0;i<tot;i++) {
        for (int j=0;j<m;j++) {
            if ((1<<j)&i){
                msb[i]=j;
                break;
            }
        }
    }
    for (int i=0;i<20;i++) {
        for (int j=1;j<tot;j++) {
            contrib[i][j]=contrib[i][j^(1<<msb[j])]+adj[i][msb[j]];
        }
    }
    for (int mask=1;mask<tot;mask++) {
        int mm = tot-1-mask;
        for (int i=0;i<m;i++){
            if ((1<<i)&mm){
                cost[mask]+=contrib[i][mask];
            }
        }
    }
    for (int i=0;i<tot;i++)dp[i]=1e18;
    dp[0]=0;
    for (int mask=0;mask<tot;mask++) {
        for (int j=0;j<m;j++) {
            if ((1<<j)&mask)continue;
            dp[mask^(1<<j)]=min(dp[mask^(1<<j)],dp[mask]+cost[mask^(1<<j)]);
        }
    }
    cout<<dp[tot-1]<<endl;
}