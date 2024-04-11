#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mid (l+r)/2
#define L (x<<1)
#define R (L+1)
int tree[4100000];
int lazy[4100000];
void lzy(int x,int l,int r) {
    tree[x]+=lazy[x];
    if (l!=r){
        lazy[L]+=lazy[x];
        lazy[R]+=lazy[x];
    }
    lazy[x]=0;
}
void upd(int x,int l,int r,int s,int e,int v){
    lzy(x,l,r);
    if (l>e || r<s)return;
    if (l>=s && r<=e){
        lazy[x]+=v;
        lzy(x,l,r);
        return;
    }
    upd(L,l,mid,s,e,v);
    upd(R,mid+1,r,s,e,v);
    tree[x]=max(tree[L],tree[R]);
}
int query(int x,int l,int r, int v){
    lzy(x,l,r);
    if (l==r){
        if (tree[x]>=v)
            return l;
        else return -1;
    } else {
        lzy(R,mid+1,r);
        if (tree[R]>=v)return query(R,mid+1,r,v);
        else return query(L,l,mid,v);
    }
}
int a[1000000];
int b[1000000];
int T[1000000];
int Id[1000000];
int V[1000000];
set<pair<pair<int,int>, int> > s;
int back[1000000];
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)scanf("%d",&a[i]), s.insert({{a[i], 0}, i});
    for (int i=1;i<=m;i++)scanf("%d",&b[i]), s.insert({{b[i], 2}, i});
    int q;
    scanf("%d",&q);
    for (int i=1;i<=q;i++){
        scanf("%d%d%d",&T[i],&Id[i],&V[i]);
        if (T[i]==1){
            s.insert({{V[i], 1}, i});
        } else {
            s.insert({{V[i], 3}, i});
        }
    }
    int cur=0;
    for (auto x:s){
        int v = x.first.first;
        int typ = x.first.second;
        int id = x.second;
        back[cur] = v;
        if (typ==0)a[id]=cur;
        else if (typ==2) b[id]=cur;
        else V[id]=cur;
        cur++;
    }
    for (int i=1;i<=n;i++){
        upd(1,0,cur,0,a[i],1);
    }
    for (int i=1;i<=m;i++){
        upd(1,0,cur,0,b[i],-1);
    }
    for (int i=1;i<=q;i++) {
        int t = T[i], id = Id[i], v=V[i];
        if (t==1){
            upd(1,0,cur,0,a[id],-1);
            a[id] = v;
            upd(1,0,cur,0,a[id],1);
        } else {
            upd(1,0,cur,0,b[id],1);
            b[id]=v;
            upd(1,0,cur,0,b[id],-1);
        }
        int ret = query(1,0,cur,1);
        if (ret!=-1)ret=back[ret];
        printf("%d\n",ret);
    }
}