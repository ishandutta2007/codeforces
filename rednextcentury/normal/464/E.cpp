#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll P1[1000000];
ll P2[1000000];
ll b1 = 1657 , m1 = 1000002499;
ll b2 = 11329, m2 = 999996131;
struct Vertex {
    Vertex *l, *r;
    int sum;
    ll h1;
    ll h2;
    Vertex(int val,int id) {
        sum = val;
        h1 = P1[id]*val;
        h2 = P2[id]*val;
        l = nullptr;
        r = nullptr;
    }
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0), h1(0), h2(0) {
        if (l) sum += l->sum , h1 = (h1+l->h1)%m1, h2 = (h2+l->h2)%m2;
        if (r) sum += r->sum , h1 = (h1+r->h1)%m1, h2 = (h2+r->h2)%m2;
    }
};

Vertex* build(int fill, int tl, int tr) {
    if (tl == tr)
        return new Vertex(fill,tl);
    int tm = (tl + tr) / 2;
    return new Vertex(build(fill, tl, tm), build(fill, tm+1, tr));
}

int get_val(Vertex* v, int tl, int tr, int id) {
    if (id<tl || id>tr)
        return 0;
    if (id == tl && tr == id)
        return v->sum;
    int tm = (tl + tr) / 2;
    return get_val(v->l, tl, tm, id)
           + get_val(v->r, tm+1, tr, id);
}

bool get_smaller(Vertex *v1, Vertex *v2, int tl, int tr){
    if (tl==tr) return v1->sum < v2->sum;
    int tm = (tl + tr) / 2;
    if (v1->l->h1 == v2->l->h1 && v1->l->h2 == v2->l->h2)
        return get_smaller(v1->r,v2->r,tm+1,tr);
    else
        return get_smaller(v1->l,v2->l,tl,tm);
}

Vertex* update(Vertex* v, int tl, int tr, int pos, int new_val) {
    if (tl == tr)
        return new Vertex(new_val,tl);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Vertex(update(v->l, tl, tm, pos, new_val), v->r);
    else
        return new Vertex(v->l, update(v->r, tm+1, tr, pos, new_val));
}

Vertex* ZeroTree;
int lst[1000000];

ll P[1000000];
Vertex* setZero(Vertex* v, Vertex* v2, int tl, int tr, int l,int r) {
    if (l>tr || r<tl)
        return v;
    if (tl>=l && tr<=r) {
        return new Vertex(v2->l,v2->r);
    }
    int tm = (tl + tr) / 2;
    return new Vertex(setZero(v->l, v2->l, tl, tm, l,r), setZero(v->r, v2->r, tm+1, tr, l, r));
}

int getLastZero(Vertex *v, int tl,int tr,int pos) {
    if (pos<tl)return -1;
    if (v->sum == tr-tl+1) return -1;
    if (tl==tr && v->sum==0 && pos>=tl)return tl;
    if (tl==tr)return -1;
    int tm = (tl+tr)/2;
    int p1 = getLastZero(v->r,tm+1,tr,pos);
    if (p1!=-1)return p1;
    return getLastZero(v->l,tl,tm,pos);
}

int mx = 1e5+100;


bool cmp(pair<Vertex*,int> a,pair<Vertex*,int> b) {
    if (a.first == NULL)return 0;
    if (b.first == NULL)return 1;
    return !get_smaller(a.first,b.first,0,mx);
}

Vertex* addBit(Vertex *root, int id) {
    auto* ret = new Vertex(root->l,root->r);
    int loc = getLastZero(ret,0,mx,id);
    //int loc = id;
    //while(get_val(ret,0,mx,loc)==1)loc--;
    if (loc<id)ret = setZero(ret,ZeroTree,0,mx,loc+1,id);
    ret = update(ret,0,mx,loc,1);
    return ret;
}
Vertex* OneTree;
Vertex* dist[1000000];
bool vis[1000000];
int back[1000000];
int n;
vector<pair<int,int> > adj[1000000];
void dijkstra(int s,int t) {
    ZeroTree = build(0,0,mx);
    OneTree = build(1,0,mx);

    priority_queue<pair<Vertex*,int> ,vector<pair<Vertex*,int> >, decltype(&cmp)> q{cmp};
    for (int i=1;i<=n;i++) {
        if (i!=s)
            dist[i] = new Vertex(OneTree->l,OneTree->r);
        else
            dist[i] = new Vertex(ZeroTree->l,ZeroTree->r);
    }
    q.push({dist[s],s});
    while(!q.empty()) {
        auto V = q.top();
        q.pop();
        if (vis[V.second])continue;
        vis[V.second]=1;
        int v = V.second;
        if (v == t)break;
        for (auto u:adj[v]) {
            if (vis[u.first])continue;
            Vertex *tmp = addBit(dist[v],u.second);
            if (get_smaller(tmp,dist[u.first],0,mx)){
                dist[u.first] = tmp;
                back[u.first] = v;
                lst[u.first] = u.second;
                q.push({dist[u.first],u.first});
            }
        }
    }
    if (back[t]==0){
        printf("-1\n");
        return;
    }
    vector<int> path;
    int v = t;
    ll mod = 1000000007;
    P[0]=1;
    ll ret = 0;
    for (int i=1;i<=mx;i++) {
        P[i]=(P[i-1]*2)%mod;
    }
    ll ret2 = 0;
    for (int i=0;i<=mx;i++){
        int cur = get_val(dist[t],0,mx,i);
        ret2=(ret2*2+cur)%mod;
    }
    while(v!=s) {
        path.push_back(v);
        ret += P[mx-lst[v]];
        ret%=mod;
        v = back[v];

    }

    path.push_back(s);
    reverse(path.begin(),path.end());
    printf("%lld\n",ret);
    printf("%d\n",(int)path.size());
    for (auto x:path)printf("%d ",x);
}
int main()
{
    int m;
    scanf("%d%d",&n,&m);
    P1[0]=P2[0]=1;
    if (n==1) {
        cout<<0<<endl<<1<<endl<<1<<endl;
        return 0;
    }
    for (int i=1;i<=mx;i++) {
        P1[i] = (P1[i-1]*b1)%m1;
        P2[i] = (P2[i-1]*b2)%m2;

    }
    for (int i=0;i<m;i++) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        w = mx-w;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
    }
    int s,t;
    scanf("%d%d",&s,&t);
    dijkstra(s,t);
}