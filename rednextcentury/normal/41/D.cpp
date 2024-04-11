#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll mem[105][105][40];
ll n,m,k;char a[105][105];
char b[105];
ll dp(int i,int j,int sum)
{
    if(i==1)
    {
        if(sum==0)
            return 0;
        return -INT_MAX;
    }
    if(mem[i][j][sum]!=-1)return mem[i][j][sum];
    if(j==1)
    {
        b[n-i]='R';
        return mem[i][j][sum]=dp(i-1,j+1,(sum+(a[i-1][j+1]-'0')+k+1)%(k+1))+a[i-1][j+1]-'0';
    }
    else if(j==m)
    {
        b[n-i]='L';
        return mem[i][j][sum]=dp(i-1,j-1,(sum+(a[i-1][j-1]-'0')+k+1)%(k+1))+a[i-1][j-1]-'0';
    }
    else
    {
        ll q=mem[i][j][sum]=dp(i-1,j-1,(sum+(a[i-1][j-1]-'0')+k+1)%(k+1))+a[i-1][j-1]-'0';
        ll t=mem[i][j][sum]=dp(i-1,j+1,(sum+(a[i-1][j+1]-'0')+k+1)%(k+1))+a[i-1][j+1]-'0';
        if(q>t)
            b[n-i]='L';
        else
            b[n-i]='R';
        return mem[i][j][sum]=max(q,t);
    }
}

void Path(int i,int j,int sum)
{
    if(i==1)
        return;
    if(j==1)
    {
        cout<<"R";
        Path(i-1,j+1,(sum+(a[i-1][j+1]-'0')+k+1)%(k+1));
        return;
    }
    else if(j==m)
    {
        cout<<"L";
        Path(i-1,j-1,(sum+(a[i-1][j-1]-'0')+k+1)%(k+1));
        return;
    }
    else
    {
        if (dp(i-1,j-1,(sum+(a[i-1][j-1]-'0')+k+1)%(k+1))+a[i-1][j-1]-'0' == mem[i][j][sum])
        {
            cout<<"L";
            Path(i-1,j-1,(sum+(a[i-1][j-1]-'0')+k+1)%(k+1));
            return;
        }
        if (dp(i-1,j+1,(sum+(a[i-1][j+1]-'0')+k+1)%(k+1))+a[i-1][j+1]-'0' == mem[i][j][sum])
        {
            cout<<"R";
            Path(i-1,j+1,(sum+(a[i-1][j+1]-'0')+k+1)%(k+1));
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    memset(mem,-1,sizeof mem);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    char r[105];ll opt=-1;ll g;
    for(int j=1;j<=m;j++)
    {
        ll e=dp(n,j,((a[n][j]-'0')+k+1)%(k+1))+(a[n][j]-'0');
        if(e>opt)
        {
            opt=e;
            for(int i=0;i<n;i++)
                r[i]=b[i];
            g=j;
        }
    }
    if(opt>=0)
    {
        cout<<opt<<endl<<g<<endl;
        Path(n,g,((a[n][g]-'0')+k+1)%(k+1));
        cout<<endl;
    }
    else
        cout<<-1;
}