#include<bits/stdc++.h>
using namespace std;
int a[1000];
int sum[1<<13][101];
int num[1<<13];
int n;
int tot[1<<13];
int val(string x)
{
    int ret=0;
    for (int i=0;i<x.size();i++)
    {
        if (x[i]=='1')
        {
            ret+=(1<<(n-i-1));
        }
    }
    return ret;
}
int calc()
{
    for (int i=0;i<(1<<n);i++)
        for (int j=0;j<n;j++)
            if ((1<<j)&i)
                tot[i]+=a[n-1-j];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m,q;
    cin>>n>>m>>q;
    for (int i=0;i<n;i++)
        cin>>a[i];
    for (int i=0;i<m;i++)
    {
        string x;
        cin>>x;
        int y = val(x);
        //cout<<y<<endl;
        num[y]++;
    }
    calc();
    for (int i=0;i<(1<<n);i++)
        for (int j=0;j<(1<<n);j++)
            if (tot[(1<<n)-1-(i^j)]<=100)
                sum[i][tot[(1<<n)-1-(i^j)]]+=num[j];
    for (int i=0;i<(1<<n);i++)
    {
        for (int j=1;j<=100;j++)
        {
            sum[i][j]+=sum[i][j-1];
        }
    }
    for (int i=0;i<q;i++)
    {
        string x;
        int k;
        cin>>x>>k;
        int y=val(x);
        cout<<sum[y][k]<<endl;
    }
}