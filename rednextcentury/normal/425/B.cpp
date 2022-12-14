#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int n,m,k;
int ans=1000;
int x[1000];
int y[1000];
int solveX()
{
    int c=0;
    for (int i=0;i<n;i++)
    {
        int num=0;
        for (int j=0;j<m;j++)
        {
            if ((1^x[j])!=a[i][j])num++;
        }
        num=min(num,m-num);
        c+=num;
    }
    return c;
}
int solveY()
{
    int c=0;
    for (int i=0;i<m;i++)
    {
        int num=0;
        for (int j=0;j<n;j++)
        {
            if (1^y[j]!=a[j][i])
                num++;
        }
        num=min(num,n-num);
        c+=num;
    }
    return c;
}
void Gen(int id)
{
    if (id==n)
    {
        ans=min(ans,solveY());
    }
    else
    {
        y[id]=1;
        Gen(id+1);
        y[id]=0;
        Gen(id+1);
    }
}
int main()
{
    cin>>n>>m>>k;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            char x;
            cin>>x;
            a[i][j]=x-'0';
        }
    }
    if (n>k)
    {
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
                x[j]=a[i][j];
            ans=min(ans,solveX());
        }
    }
    else
        Gen(0);
    if (ans>k)cout<<-1<<endl;
    else cout<<ans<<endl;
}