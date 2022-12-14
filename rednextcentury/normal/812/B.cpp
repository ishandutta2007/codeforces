#include <bits/stdc++.h>
using namespace std;
int mn[1000];
int mx[1000];
int ret=(1<<25);
int n,m;
int ex;
void solve(int i,int j,int cost)
{
    if (i==ex)
    {
        if (j==0)
            cost+=mx[i];
        else
            cost+=j-mn[i];
        ret=min(ret,cost);
    }
    else
    {
        if (j==0)
        {
            solve(i-1,m-1,cost+m);
            solve(i-1,0,cost+1+mx[i]*2);
        }
        else
        {
            solve(i-1,0,cost+m);
            solve(i-1,m-1,cost+1+((mn[i]==0)?0:(m-1-mn[i])*2));
        }
    }
}
int main()
{
    cin>>n>>m;
    m+=2;
    bool has=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            char x;
            cin>>x;
            if (x=='1')
                mx[i]=j,has=1;
            if (x=='1' && mn[i]==0)
                mn[i]=j;
        }
        if (has==0)
            ex=i+1;
    }
    if (ex==n)
        cout<<0<<endl;
    else{
        solve(n-1,0,0);
        cout<<ret<<endl;
    }
}