#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
vector<ll> a;
bool check(int n,const vector<int>&p,ll S)
{
    bool a[n][n],b[n][n],c[n],d[n];
    memset(a,0,sizeof a);
    memset(b,0,sizeof b);
    memset(c,0,sizeof c);
    memset(d,0,sizeof d);
    for(int i=0;i<n;i++)c[i]=1;
    for(int i=0;i<n-1;i++)a[i][i+1]=1;
    for(int i=0;i<p.size();i++)a[n-1][n-1-p[i]]=1;
    while(S)
    {
        if(S&1)
        {
            memset(d,0,sizeof d);
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    d[k]^=(c[j]&a[j][k]);
            memcpy(c,d,sizeof c);
        }
        memset(b,0,sizeof b);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    b[i][k]^=(a[i][j]&a[j][k]);
        memcpy(a,b,sizeof a);
        S/=2;
    }
    for(int i=0;i<n;i++)if(c[i]!=1)return 0;
    return 1;
}
bool check(int n,const vector<int>&p)
{
    if(!check(n,p,a[0]))return 0;
    for(int i=1;i<a.size();i++)
        if(check(n,p,a[i]))return 0;
    return 1;
}
void random(int n,vector<int>&p)
{
    p.clear();
    for(int i=0;i<n;i++)
        if(rand()&1)p.push_back(i);
}
void precalc(int n)
{
    ll S=1;
    for(int i=0;i<n;i++)S*=2;
    S-=1;
    a.push_back(S);
    ll T=S;
    for(int i=2;i<=33555555;i++)
        if(T%i==0)
        {
            a.push_back(S/i);
            while(T%i==0)T/=i;
        }
    if(T!=1)a.push_back(S/T);
}
string calc(int n)
{
    precalc(n);
    vector<int> p;
    random(n,p);
    while(!check(n,p))random(n,p);
    string s="0";
    for(int i=1;i<n;i++)s+=" 0";
    for(int i=0;i<p.size();i++)s[2*p[i]]='1';
    return s;
}
int main()
{
    int n;scanf("%d",&n);
    cout<<calc(n)<<endl;
    string s="1";
    for(int i=1;i<n;i++)s+=" 1";
    cout<<s<<endl;
    return 0;
}