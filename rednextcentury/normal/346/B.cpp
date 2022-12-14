# include<iostream>
#include<string>
#define MOD 1000000007
using namespace std;
int n,m,k;
string v,s1,s2;
int pre[1000000];
void PRE()
{
    int i = 0, j = -1;
    pre[0] = -1;
    while (i < k)
    {
        while (j >= 0 && v[j] != v[i])
            j = pre[j];
        i++,j++;
        pre[i] = j;
    }
}
int dp[101][101][101];
bool vis[101][101][101];
int nxt[101][101][101][3];
int solve(int i,int j,int x)
{
    if (i==n || j==m)
    {
        if (x==k)
            return -1000000;
        else
            return 0;
    }
    if (x==k)
        return -10000000;
    if (vis[i][j][x]) return dp[i][j][x];
    vis[i][j][x]=1;
    int mx=-10000000,l1=solve(i+1,j,x),l2=solve(i,j+1,x),l3=-1000000;
    int y=0;

        mx=l1;
        nxt[i][j][x][0]=i+1,nxt[i][j][x][1]=j,nxt[i][j][x][2]=x;
    if (l2>mx)
    {
        mx=l2;
        nxt[i][j][x][0]=i,nxt[i][j][x][1]=j+1,nxt[i][j][x][2]=x;
    }

    if (s1[i]==s2[j])
    {
        y=x;
        while(y>=0 && v[y]!=s1[i])
            y=pre[y];
        l3=solve(i+1,j+1,++y)+1;
        if (l3>mx)
        {
            mx=l3;
            nxt[i][j][x][0]=i+1,nxt[i][j][x][1]=j+1,nxt[i][j][x][2]=y;
        }
    }
    return dp[i][j][x]=mx;
}
int main()
{
    cin>>s1>>s2>>v;
    n=s1.length(),m=s2.length(),k=v.length();
    PRE();
    solve(0,0,0);
    int i=0,j=0,x=0;
    string res="";
    while(1)
    {
        int ii=nxt[i][j][x][0];
        int jj=nxt[i][j][x][1];
        int xx=nxt[i][j][x][2];
        if (i>=ii && j>=jj)
            return 1;
        if (ii==i+1 && jj==j+1)
            res+=s1[i];
        i=ii,j=jj,x=xx;
        if (i==n || j==m)
            break;
    }
    if (res.length()!=0)
        cout<<res<<endl;
    else
        cout<<0<<endl;
}