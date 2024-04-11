#include<bits/stdc++.h>
using namespace std;
vector<long long > em;
long long  mod=(1000000007);
void mult (vector<vector<long long > >&a,vector<vector<long long > >&b,vector<vector<long long > >&c)
{
    long long  m=a.size(),n=a[0].size(),k=b[0].size();
    vector<vector<long long > > ans;
    for (long long  i=0; i<m; i++)
    {
        ans.push_back(em);
        for (long long  j=0; j<k; j++)
            ans[i].push_back(0);
    }
    for (long long  i=0; i<m; i++)
        for (long long  j=0; j<n; j++)
            for (long long  p=0; p<k; p++)
                ans[i][p]=(ans[i][p]+a[i][j]*b[j][p])%mod;
    c=ans;
}
void exp (vector<vector<long long > > &a, long long  N, vector<vector<long long > > &c)
{
    vector<vector<long long > > ans;
    for (long long  i=0; i<a.size(); i++)
    {
        ans.push_back(em);
        for (long long  j=0; j<a.size(); j++)
            if(i==j) ans[i].push_back(1);
        else ans[i].push_back(0);
    }
    for(long long  i=30; i>=0; i--)
    {
        mult(ans,ans,ans);
        if((1<<i)&N) mult(ans,a,ans);
    }
    c=ans;
}

long long  f[400];
main()
{

    long long  n,b,k,x;
    cin>>n>>b>>k>>x;
    vector<vector<long long > > v,h;
    for (long long  i=0; i<x; i++)
    {
        v.push_back(em);
        for (long long  j=0; j<x; j++)
            v[i].push_back(0);
    }
    for (long long  i=0; i<n; i++)
    {
        long long  a;
        cin>>a;
        f[a%x]++;
    }
h.push_back(em);
    for (long long  i=0; i<x; i++)
       {
       h[0].push_back(f[i]);}
    for (long long  i=0; i<x; i++)
        for (long long  j=0; j<x; j++)
    {
        for (long long  k=0; k<x; k++)
            if((10*j+k)%x==i) v[j][i]+=f[k];
    }
    exp(v,b-1,v);
    mult(h,v,h);
    cout<<h[0][k]<<endl;
}