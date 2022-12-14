#include<bits/stdc++.h>
using namespace std;
#define L (x<<1)
#define R (L+1)
#define mid (l+r)/2
pair<long long,int>  tree[4000100];
long long lazy[4000100];
void build(int x,int l,int r)
{
    if (l==r)tree[x].second=l;
    else
    {
        build(L,l,mid);build(R,mid+1,r);
        tree[x]=max(tree[L],tree[R]);
    }
}
void lzy(int x,int l,int r)
{
    tree[x].first+=lazy[x];
    if (l!=r)
    {
        lazy[L]+=lazy[x];
        lazy[R]+=lazy[x];
    }
    lazy[x]=0;
}
void upd(int x,int l,int r,int s,int e,long long v)
{
    lzy(x,l,r);
    if (l>e || r<s)return;
    if (l>=s && r<=e)
    {
        lazy[x]+=v;
        lzy(x,l,r);
        return;
    }
    upd(L,l,mid,s,e,v);
    upd(R,mid+1,r,s,e,v);
    tree[x]=max(tree[L],tree[R]);
}
int cur;
pair<long long,int> query(int x,int l,int r,int s,int e)
{
    lzy(x,l,r);
    if (l>e || r<s)return {-1e18,-1};
    if (l>=s && r<=e)return tree[x];
    return max(query(L,l,mid,s,e),query(R,mid+1,r,s,e));
}
int x[1000000];
int y[1000000];
int c[1000000];
set<int> s;
map<int,int> mp;
long long val[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i]>>c[i];
        s.insert(x[i]);
        s.insert(y[i]);
    }
    for (auto x:s)val[cur]=x,mp[x]=cur++;
    build(1,0,cur-1);
    for (int i=0;i<cur;i++)
        upd(1,0,cur-1,i,i,val[i]);
    vector<pair<int,int> > events;
    for (int i=0;i<n;i++)
    {
        x[i]=mp[x[i]];
        y[i]=mp[y[i]];
        events.push_back({max(x[i],y[i]),i});
    }
    sort(events.begin(),events.end());
    long long ret=0;
    int LX=2e9,RX=2e9,LY=2e9,RY=2e9;
    for (int i=0;i<events.size();i++)
    {
        pair<int,int> e = events[i];
        int X = min(x[e.second],y[e.second]);
        upd(1,0,cur-1,0,X,c[e.second]);
        if (i+1 == events.size() || events[i+1].first!=events[i].first){
            auto q = query(1,0,cur-1,0,e.first);
            long long cur = q.first-val[e.first];
            if (cur>ret)
            {
                ret=cur;
                LX = LY = val[q.second];
                RX = RY = val[e.first];
            }
        }
    }
    cout<<ret<<endl;
    cout<<LX<<' '<<LY<<' '<<RX<<' '<<RY<<endl;
}