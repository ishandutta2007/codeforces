#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
set<int> st;
int a[3000000];
int tree[3000000];
void build(int x,int l,int r)
{
    if (l==r)tree[x]=a[l];
    else
    {
        build(x*2,l,(l+r)/2);
        build(x*2+1,(l+r)/2+1,r);
        tree[x]=min(tree[x*2],tree[x*2+1]);
    }
}
int query(int x,int l,int r,int s,int e)
{
    if (l>e || r<s)
        return 1e9;
    if (l>=s && r<=e)
        return tree[x];
    return min(query(x*2,l,(l+r)/2,s,e),query(x*2+1,(l+r)/2+1,r,s,e));
}
int l[3000000];
int r[3000000];
set<int> s;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>l[i]>>r[i];
        s.insert(l[i]);
        s.insert(l[i]-1);
        //s.insert(l[i]+1);
        //s.insert(r[i]+1);
        //s.insert(r[i]-1);
        s.insert(r[i]);
    }
    int cur=0;
    for(auto x:s)
    {
        mp[x]=cur++;
    }
    for (int i=0;i<n;i++)
    {
        l[i]=mp[l[i]];
        r[i]=mp[r[i]];
        a[l[i]]++,a[r[i]+1]--;
    }
    for (int i=1;i<cur;i++)
        a[i]+=a[i-1];
    build(1,0,cur);
    for (int i=0;i<n;i++)
    {
        if (query(1,0,cur,l[i],r[i])>1)
        {
            cout<<i+1<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}