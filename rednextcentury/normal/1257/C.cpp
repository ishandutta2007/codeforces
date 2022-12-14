#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000000];
int last[1000000];
int nxt[1000000];
int dp[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for (int i=1;i<=n;i++)
            last[i]=1e7;
        for (int i=1;i<=n;i++)
            cin>>a[i];
        dp[n+1]=1e7;
        for (int i=n;i>=1;i--) {
            nxt[i]=1e7;
            if (last[a[i]]<=n)nxt[i]=last[a[i]];
            last[a[i]]=i;
            dp[i]=nxt[i];
            dp[i]=min(dp[i+1],nxt[i]);
        }
        int ret=1e9;
        for (int i=1;i<=n;i++){
            if (nxt[i]==1e7)continue;
            if (nxt[i]==dp[i])ret=min(ret,nxt[i]-i+1);
        }
        if (ret>n)ret=-1;
        cout<<ret<<endl;
    }
}