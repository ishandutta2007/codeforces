#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<ll,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,m,q,cnt[MAXN];
vector<P> queries;
vector<int> id[MAXN];
vector<int> v;
int save[MAXN];
int ans[MAXN];
inline bool scan_l(ll &num)  
{
        char in;bool IsN=false;
        in=getchar();
        if(in==EOF) return false;
        while(in!='-'&&(in<'0'||in>'9')) in=getchar();
        if(in=='-'){ IsN=true;num=0;}
        else num=in-'0';
        while(in=getchar(),in>='0'&&in<='9'){
                num*=10,num+=in-'0';
        }
        if(IsN) num=-num;
        return true;
}
inline bool scan_d(int &num)  
{
        char in;bool IsN=false;
        in=getchar();
        if(in==EOF) return false;
        while(in!='-'&&(in<'0'||in>'9')) in=getchar();
        if(in=='-'){ IsN=true;num=0;}
        else num=in-'0';
        while(in=getchar(),in>='0'&&in<='9'){
                num*=10,num+=in-'0';
        }
        if(IsN) num=-num;
        return true;
}
struct segtree
{
    int cnt[4*MAXN];
    void pushup(int k)
    {
        cnt[k]=cnt[k*2]+cnt[k*2+1];
    }
    void add(int k,int l,int r,int x)
    {
        if(l==r) {cnt[k]++; return;}
        int mid=(l+r)/2;
        if(x<=mid) add(k*2,l,mid,x); else add(k*2+1,mid+1,r,x);
        pushup(k);
    }
    int query(int k,int l,int r,int x)
    {
        if(l==r) return l;
        int mid=(l+r)/2;
        if(cnt[k*2]>=x) return query(k*2,l,mid,x); else return query(k*2+1,mid+1,r,x-cnt[k*2]);
    }
}seg;
void merge_id(int y)
{
    for(auto p:id[y]) seg.add(1,1,m,p);
}
int main()
{
    scan_d(n); scan_d(m); scan_d(q);
    for(ll i=1;i<=n;i++)
    {
        int x;
        scan_d(x);
        cnt[x]++;
    }
    for(ll i=0;i<q;i++)
    {
        ll k;
        scan_l(k);
        queries.push_back(P(k,i));
    }
    sort(queries.begin(),queries.end());
    for(ll i=1;i<=m;i++)
    {
        v.push_back(cnt[i]);
        id[cnt[i]].push_back(i);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    ll now=n;
    int cur=0,tot=(int)id[v[cur]].size(); 
    for(auto x:id[v[0]]) seg.add(1,1,m,x);
    for(ll i=0;i<q;i++)
    {
        ll need=queries[i].F-now;
        while(cur!=(int)v.size()-1&&1LL*(v[cur+1]-v[cur])*tot<need)
        {
            now+=1LL*(v[cur+1]-v[cur])*tot;
            need-=1LL*(v[cur+1]-v[cur])*tot;
            merge_id(v[cur+1]);
            cur++;
            tot+=(int)id[v[cur]].size();
        }
        ll idx=(need-1)%tot;
        ans[queries[i].S]=seg.query(1,1,m,idx+1);
    }
    for(ll i=0;i<q;i++) printf("%d\n",ans[i]);
    return 0;
}