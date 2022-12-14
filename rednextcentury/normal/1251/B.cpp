#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[3000];
int dp[100][2][2];
int n;
int sol(int i,int x,int y) {
    if (i==n) {
        if (x==0 && y==0)return 0;
        else return -1e9;
    }
    if (dp[i][x][y]!=-1) {
        return dp[i][x][y];
    }
    dp[i][x][y]=-1e9;
    for (int p=0;p<=1;p++) {
        for (int q=0;q<=1;q++) {
            if ((p+q)%2 != a[i]%2)continue;
            dp[i][x][y]=max(dp[i][x][y],sol(i+1,x^p,y^q)+(q+p<=1));
        }
    }
    return dp[i][x][y];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        memset(dp,-1,sizeof(dp));
        cin>>n;
        int cnt[2]={0};
        for (int i=0;i<n;i++) {
            string s;
            cin>>s;
            a[i]=s.size();
            for (auto x:s)cnt[x-'0']++;
        }
        cout<<sol(0,cnt[0]%2,cnt[1]%2)<<endl;
    }
}