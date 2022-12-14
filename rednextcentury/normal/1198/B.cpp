#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[1000000];
int tree[5000000];
void upd(int x,int l,int r,int v,int val)
{
    if (v>r || v<l)return;
    if (l==r)tree[x]=val;
    else
    {
        upd(x*2,l,(l+r)/2,v,val);
        upd(x*2+1,(l+r)/2+1,r,v,val);
        tree[x]=max(tree[x*2],tree[x*2+1]);
    }
}
int query(int x,int l,int r,int s,int e)
{
    if (l>e || r<s)return 0;
    if (l>=s && r<=e)return tree[x];
    return max(query(x*2,l,(l+r)/2,s,e),query(x*2+1,(l+r)/2+1,r,s,e));
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i].first;
    int q;
    cin>>q;
    int X = 0 , last=0;
    for (int i=1;i<=q;i++)
    {
        int t;
        cin>>t;
        if (t==1)
        {
            int p,x;
            cin>>p>>x;
            a[p].first=x;
            a[p].second=i;
        }
        else
        {
            int x;
            cin>>x;
            upd(1,0,q,i,x);
        }
    }
    for (int i=1;i<=n;i++)
    {
        int L = a[i].second;
        int R = q;
        int X = query(1,0,q,L,R);
        if (X>a[i].first)a[i].first=X;
        cout<<a[i].first<<' ';
    }
    cout<<endl;
}