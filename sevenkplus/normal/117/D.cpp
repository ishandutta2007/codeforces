#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n;int m,P,P2,S;
void ff(ll n,ll nl,ll nr,ll l,ll r,ll u,ll v,ll s,ll t)
{
    if(v<s||u>s+(n-1)*t||l>r)return;
    if(l<=nl&&nr<=r)
    {
        u=max(u,s);
        ll s1=s+t*((u+t-1-s)/t),t1=s+t*min(n-1,((v-s)/t));
        S=((ll)S+((s1+t1)%P2)*(((t1-s1)/t+1)%P2))%(P2);
        return;
    }
    ll nm=(nl+nr)/2;
    if(l<=nm)ff((n+1)/2,nl,nm,l,r,u,v,s,t*2);
    if(nm<r)ff(n/2,nm+1,nr,l,r,u,v,s+t,t*2);
}
int main()
{
    cin>>n>>m>>P;P2=P*2;
    for(int i=0;i<m;i++)
    {
        ll l,r,u,v;
        cin>>l>>r>>u>>v;
        S=0,ff(n,1,n,l,r,u,v,1,1);
        cout<<S/2<<"\n";
    }
    return 0;
}