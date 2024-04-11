#include<bits/stdc++.h> 
using namespace std; 
#define ll long long int
#define v vector<ll>
#define vv vector<v>
// #define p pair<ll,ll>
// #define MAX 15000001
#define fi first
#define se second
#define mid (start+end)/2
ll MAX=1e6+100;
v Count(4*MAX+100,0);
v total(4*MAX+100,0);
void update(ll node, ll start, ll end, ll idx, ll val, v&tree)
{
    if(start == end)
    {
        // A[idx] += val;
        tree[node] += val;
    }
    else
    {
        // ll mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            update(2*node, start, mid, idx, val,tree);
        }
        else
        {
            update(2*node+1, mid+1, end, idx, val,tree);
        }
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

ll query(ll node, ll start, ll end, ll l, ll r,v &tree)
{
    if(r < start or end < l)
    {
        return 0;
    }
    if(l <= start and end <= r)
    {
        return tree[node];
    }
    // ll mid = (start + end) / 2;
    ll p1 = query(2*node, start, mid, l, r,tree);
    ll p2 = query(2*node+1, mid+1, end, l, r,tree);
    return (p1 + p2);
}

ll query2(ll node,ll start,ll end,ll k,v &tree)
{
    if (start==end)
        return start;
    if (tree[node*2]<k)
        return query2(2*node+1,mid+1,end,k-tree[node*2],tree);
    else
        return query2(2*node,start,mid,k,tree);
}
ll k;
ll find()
{
    if (query(1,1,MAX,1,MAX,Count)<k)
        return query(1,1,MAX,1,MAX,total);
    ll a=query2(1,1,MAX,k,Count);
    ll b=0;
    if (a>1)
        b=query(1,1,MAX,1,a-1,Count);
    ll sum=0;
    if (a>1)
        sum=query(1,1,MAX,1,a-1,total);
    // cout<<sum<<endl;
    sum=sum+(k-b)*a;
    return sum;
}

ll LIM=1e6+100;
int main() {
    ll n,m;
    cin>>n>>k>>m;
    vv start(MAX+100),end(MAX+100);
    vector<pair<ll,ll> > segments(m+1);
    v cost(MAX+100,0);
    v cores(MAX+100,0);
    for (ll i=1; i<=m; i++)
    {
        cin>>segments[i].fi>>segments[i].second;//endl;
        cin>>cores[i]>>cost[i];
        start[segments[i].fi].push_back(i);
        end[segments[i].se].push_back(i);
    }
    ll ans=0;
    for (ll i=1; i<=n; i++)
    {
        for (ll j=0; j<start[i].size(); j++)
        {
            ll price=cost[start[i][j]];
            ll c=cores[start[i][j]];
            update(1,1,MAX,price,c,Count);
            update(1,1,MAX,price,c*price,total);
        }
        ll sum=find();
        ans+=sum;
        for (ll j=0; j<end[i].size(); j++)
        {
            ll price=cost[end[i][j]];
            ll c=cores[end[i][j]];
            update(1,1,MAX,price,-c,Count);
            update(1,1,MAX,price,-c*price,total);
        }
    }
    cout<<ans<<endl;
    return 0;
}