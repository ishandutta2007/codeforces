#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll n,m,k;
ll a[200];
ll b[200][200];
ll mem[120][120][120];
ll dinamic_prgramming(int i,int k,int j)
{
    if(i==n+1)
    {
        if(k==0)
            return 0;
        else
            return +1e13;
    }
    if(mem[i][k][j]!=-1)return mem[i][k][j];
    if(a[i]!=0)return mem[i][k][j]=dinamic_prgramming(i+1,k-(a[i]!=j),a[i]);
    ll q=1e13;
    for(int p=1;p<=m;p++)
    {
        int newK = k;
        if (p!=j)
            newK--;
        ll w=dinamic_prgramming(i+1,newK,p)+b[i][p];
        q=min(q,w);
    }
    return mem[i][k][j]=q;
}


int main()
{
    ios::sync_with_stdio(false);
    memset(mem,-1,sizeof mem);
    cin>>n>>m>>k;
    for(int i=1 ;i<=n;i++)
    {
        cin>>a[i];
    }
    ll t=1;ll x=1e13;
    for(int i=1 ;i<=n;i++)
        for(int j=1 ;j<=m;j++)
        {
            cin>>b[i][j];
        }
    ll ret = dinamic_prgramming(1,k,0);
    if (ret==x)ret=-1;
    cout<<ret<<endl;







}