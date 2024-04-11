#include<bits/stdc++.h>
using namespace std;
int m;
string s;
int mx[101][51][5];
int mn[101][51][5];
int MAX(int i,int n,int op)
{
    if (n<0)return -1000000;
    if (i==m && n==0)return 0;
    if (i==m)return -1000000;
    if (mx[i][n][op]!=-1)return mx[i][n][op];
    mx[i][n][op]=0;
    if (s[i]=='F')
        mx[i][n][op]=max(MAX(i+1,n,op)+op-1,MAX(i+1,n-1,2-op));
    else
        mx[i][n][op]=max(MAX(i+1,n-1,op)+op-1,MAX(i+1,n,2-op));
    return mx[i][n][op];
}
int main()
{
    memset(mn,-1,sizeof(mn));
    memset(mx,-1,sizeof(mx));
    int n;
    cin>>s>>n;
    m=s.length();
    int ans=0;
    for (int i=n;i>=0;i-=2)
        ans=max(ans,max(MAX(0,i,2),MAX(0,i,0)));
    cout<<ans<<endl;
}