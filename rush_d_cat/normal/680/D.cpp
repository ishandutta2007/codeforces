#include<iostream>
#include<cstring>
#include<string.h>
#include<cstdio>
#include<stdio.h>
using namespace std;
typedef __int64 ll;
ll max_b=0,max_v=0;
ll f(ll x)
{
    return x*x*x;
}
void dfs(ll m,ll p,ll v)
{
    if(m==0)
    {
        if(p>max_b){
            max_b=p;
            max_v=v;
        }
        if(p==max_b){
            max_b=p;
            max_v = max(v,max_v);
        }
        return;
    }
    ll t=0;while(f(t+1)<=m) t++;
    dfs(m-f(t),p+1,v+f(t));
    dfs(f(t)-f(t-1)-1,p+1,v+f(t-1));
}
int main()
{
    ll m;cin>>m;
    dfs(m,0,0);
    cout<<max_b<<" "<<max_v<<endl;
    return 0;
}