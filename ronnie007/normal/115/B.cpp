#include<iostream>
#include<stdio.h>
using namespace std;

int n,m;
string a[157];
int dp[157][157];
int odd[157];
int oddp[157];


void dfs(int x,int y);

int main()
    {
    cin>>n>>m;
    int i,j;
    int f,l;
    for(i=0;i<n;i++)
        {
        cin>>a[i];
        f=1000000;
        l=-1;
        for(j=0;j<m;j++)
            {
            if(a[i][j]=='W')
                {
                if(f==1000000)f=j;
                l=j;
                }
            dp[i][j]=10000000;
            }
        if(i%2==0){odd[i]=l;oddp[i]=f;}
        else {odd[i]=f;oddp[i]=l;}
        ///cout<<oddp[i]<<"\n";
        }
    dp[0][0]=0;
    dfs(0,0);
    ///cout<<"here127\n";
    /**
    for(i=0;i<n;i++)
        {
        for(j=0;j<m;j++)
            {
            cout<<dp[i][j]<<" ";
            }
        cout<<"\n";
        }
    **/
    for(i=n-1;i>=0;i--)
        {
        if(odd[i]!=-1 && odd[i]!=1000000){cout<<dp[i][odd[i]]<<"\n";return 0;}
        }
    cout<<"0\n";
    return 0;
    }


void dfs(int x,int y)
    {
    ///cout<<x<<" " <<y<<"\n";
    if(y<m-1 && x%2==0 && dp[x][y+1]>dp[x][y]+1)
        {
        dp[x][y+1]=dp[x][y]+1;
        dfs(x,y+1);
        }
    if(y>0 && x%2==1 && dp[x][y-1]>dp[x][y]+1)
        {
        dp[x][y-1]=dp[x][y]+1;
        dfs(x,y-1);
        }
    ///cout<<"here\n";
    if(y<=odd[x] && x%2==1 && x!=n-1 && dp[x+1][y]>=dp[x][y]+1 && (y<=oddp[x+1] || oddp[x+1]==-1))
        {
        dp[x+1][y]=dp[x][y]+1;
        dfs(x+1,y);
        }

    if(y>=odd[x] && x%2==0 && x!=n-1 && dp[x+1][y]>=dp[x][y]+1 && (y>=oddp[x+1] || oddp[x+1]==-1))
        {
        dp[x+1][y]=dp[x][y]+1;
        dfs(x+1,y);
        }
    ///if(x==19)cout<<"here\n";
    }