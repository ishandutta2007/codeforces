#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mid ((l+r)/2)
#define L (x<<1)
#define R (L+1)
int dp[1000000][2];
int a[1000000];
int n;
int vis[1000000][2];
int T;
int solve(int i,int j)
{
    if (i==n)return 0;
    if (i==n-1 && j==0)return 0;
    if (i==n-1 && j==1) {
        if (a[i]==1)return 0;
        else return 1;
    }
    if (vis[i][j]==T)return dp[i][j];
    vis[i][j]=T;
    dp[i][j]=1e9;
    int l,r,x;
    if (j==0){
        l=a[i],r=a[i+1],l=r+1,x=a[i+2];
        dp[i][j]=min(dp[i][j],solve(i+2,(x!=l-2))+1-(x==l-2));
        dp[i][j]=min(dp[i][j],solve(i+1,0)+1);
    }
    else {
        l=a[i]+1;
        r=a[i];
        x=a[i+1];
        dp[i][j]=min(dp[i][j],solve(i+2-j,(x!=l-2))+1-(x==l-2));
        dp[i][j]=min(dp[i][j],solve(i+1-j,0)+1);
    }
    return dp[i][j];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    string s;
    cin>>n>>s;
    long long ret = n;
    ret=ret*(ret-1)/2;
    for (int i=0;i+1<n;i++)if (s[i]!=s[i+1])ret--;
    int cur=0;
    char last='0';
    for (int i=0;i<n;i++) {
        if (s[i]==last)cur++;
        else {
            if (cur>0)ret-=cur-1;
            cur=1;
            last=s[i];
        }
    }
    reverse(s.begin(),s.end());
    cur=0;
    last='0';
    for (int i=0;i<n;i++) {
        if (s[i]==last)cur++;
        else {
            if (cur>0)ret-=cur-1;
            cur=1;
            last=s[i];
        }
    }
    cout<<ret<<endl;

}