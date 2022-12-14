#include <bits/stdc++.h>
using namespace std;
#define ll long long
pair<ll,pair<ll,ll> > a[1000000];
ll tree[1000000];
void upd(int x,int l,int r,int v,ll val)
{
    if (v>r || v<l)return;
    if (l==r)tree[x]=max(tree[x],val);
    else
    {
        upd(x*2,l,(l+r)/2,v,val);
        upd(x*2+1,(l+r)/2+1,r,v,val);
        tree[x]=max(tree[x*2],tree[x*2+1]);
    }
}
ll query(int x,int l,int r,int s,int e)
{
    if (e<l || r<s)
        return 0;
    if (l>=s && r<=e)
        return tree[x];
    return max(query(x*2,l,(l+r)/2,s,e),query(x*2+1,(l+r)/2+1,r,s,e));
}
ll A[1000000];
ll B[1000000];
ll H[1000000];
map<int,ll> mp;
map<int,ll> mn;
map<int,int> M;
set<int> S;
ll dp[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>A[i]>>B[i]>>H[i];
        mp[B[i]]+=H[i];
        if (mp[B[i]]==H[i])
            mn[B[i]]=A[i];
        else
            mn[B[i]]=min(mn[B[i]],A[i]);
    }
    n=0;
    for (map<int,ll>::iterator it=mp.begin();it!=mp.end();it++)
    {
        int BB = it->first;
        A[n]=mn[BB];
        S.insert(A[n]);
        S.insert(BB);
        B[n]=BB;
        H[n++]=it->second;
    }
    int tot=1;
    for (set<int>::iterator it=S.begin();it!=S.end();it++)
    {
        M[*it]=tot++;
    }
    for (int i=0;i<n;i++)
    {
        a[i].first = M[B[i]];
        a[i].second.first = M[A[i]];
        a[i].second.second=H[i];
    }
    sort(a,a+n);
    ll ret=0;
    for (int i=n-1;i>=0;i--)
    {
        //cout<<a[i].first<<' '<<a[i].second.first<<' '<<a[i].second.second<<endl;
        dp[i]=query(1,1,tot,1,a[i].first-1)+a[i].second.second;
        ret=max(ret,dp[i]);
        upd(1,1,tot,a[i].second.first,dp[i]);
    }
    cout<<ret<<endl;
}