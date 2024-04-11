#include<bits/stdc++.h>
const int N=1e6+5;
using namespace std;
int tree[N];
int a[N];
int dp[N];
void upd(int x,int l,int r,int v,int val)
{
    if (v<l || v>r)
        return;
    if (l==r)
        tree[x]=val;
    else
    {
        upd(x*2,l,(l+r)/2,v,val);
        upd(x*2+1,(l+r)/2+1,r,v,val);
        tree[x]=max(tree[x*2],tree[x*2+1]);
    }
}
int query(int x,int l,int r,int s,int e)
{
    if (l>e || r<s)
        return 0;
    if (l>=s && r<=e)
        return tree[x];
    return max(query(x*2,l,(l+r)/2,s,e),query(x*2+1,(l+r)/2+1,r,s,e));
}
int calc(int n)
{
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        dp[i]=query(1,1,n,1,a[i])+1;
        upd(1,1,n,a[i],dp[i]);
        ans=max(ans,dp[i]);
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    cout<<calc(n)<<endl;
}