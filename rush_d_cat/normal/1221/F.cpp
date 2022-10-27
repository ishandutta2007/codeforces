// 04:32
#include <iostream>
#include <vector>
#include <map>
#include <assert.h>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 1000000 + 10;
int n;int x[N],y[N],c[N];
vector<int> vx[N],vy[N],v;
int tx[N],ty[N];
bool cmpx(int i,int j) {
    return x[i] < x[j];
}
bool cmpy(int i,int j) {
    return y[i] < y[j];
}
int id(LL x) {
    return lower_bound(v.begin(),v.end(),x) - v.begin() + 1;
}
struct Nod {
    LL mx,lz,pos;
    Nod operator+(const Nod&o) const{
        Nod ans; ans.lz = 0;
        ans.mx = max(mx, o.mx);
        if(ans.mx == mx) ans.pos = pos;
        if(ans.mx == o.mx) ans.pos = o.pos;
        return ans;
    }
} nod[N<<2];   
void upd(Nod& tmp,LL x) {
    tmp.lz += x; tmp.mx += x;
}
void build(int l,int r,int rt) {
    nod[rt].mx = 0, nod[rt].lz = 0; nod[rt].pos = l;
    if(l==r) {
        nod[rt].pos=l; return;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
}
void pushdown(int rt) {
    if(nod[rt].lz) {
        upd(nod[rt<<1], nod[rt].lz);
        upd(nod[rt<<1|1], nod[rt].lz);
        nod[rt].lz = 0;
    }
}
void update(int l,int r,int rt,int L,int R,int x) {
    if(L<=l&&r<=R) {
        upd(nod[rt], x); return;
    }
    int mid=(l+r)>>1; pushdown(rt);
    if(L<=mid) update(l,mid,rt<<1,L,R,x);
    if(R >mid) update(mid+1,r,rt<<1|1,L,R,x);
    nod[rt]=nod[rt<<1] + nod[rt<<1|1];
}
Nod query(int l,int r,int rt,int L,int R){
    if(L<=l&&r<=R) return nod[rt];
    int mid=(l+r)>>1; pushdown(rt);
    if (R<=mid) return query(l,mid,rt<<1,L,R);
    if (L >mid) return query(mid+1,r,rt<<1|1,L,R);
    return query(l,mid,rt<<1,L,R) + query(mid+1,r,rt<<1|1,L,R);
}
/*
void brt() {
    LL ans=-1e9;
    for(int a=0;a<=100;a++)for(int b=a;b<=100;b++){
        LL s=0;
        for(int i=1;i<=n;i++)
            if(x[i]<=b&&x[i]>=a && y[i]<=b && y[i]>=a)
                s += c[i];
        ans=max(ans, s-(b-a));
    }
    printf("%d\n", ans);
}
*/
int main() {
    scanf("%d", &n);
    //n = 100;
    map<int,int> mp;
    for(int i=1;i<=n;i++) {
        scanf("%d%d%d",&x[i],&y[i],&c[i]);
        //x[i]=rand()%100, y[i]=rand()%100, c[i]=rand()%1000000-600000;
        //printf("%d %d %d\n", x[i],y[i],c[i]);
        v.push_back(x[i]); v.push_back(y[i]);
        mp[x[i]] = mp[y[i]] = 1;
    }
    sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()), v.end());
    for(int i=1;i<=n;i++) {
        vx[id(x[i])].push_back(i);
        vy[id(y[i])].push_back(i);
    }
    int tot=v.size();
    for(int i=1;i<=tot;i++) {
        sort(vx[i].begin(), vx[i].end(), cmpy);
        sort(vy[i].begin(), vy[i].end(), cmpx);
    }
    build(1,tot,1);
    LL ans = -1, ax, ay;  
    for(int i=1;i<=tot;i++) {
        if(i>=2) {
           // printf("update %d %d %d\n", 1,i-1,v[i-2] - v[i-1]);
            assert(v[i-2] - v[i-1] >= -1e9);
            update(1,tot,1,1,i-1,v[i-2] - v[i-1]);
        }
        while(tx[i]<vx[i].size()) {
            int id_=vx[i][tx[i]]; tx[i]++;
            //printf("id_ = %d\n", id_);
            if(id(y[id_]) <= i) {
                //printf("join x %d, update %d %d %d\n", id_, 1,id(y[id_]),c[id_]);
                update(1,tot,1,1,id(y[id_]),c[id_]); 
            } else {
                break;
            }
        }
        while(ty[i]<vy[i].size()) {
            int id_=vy[i][ty[i]]; ty[i]++;
            if(id(x[id_])  < i) {
                //printf("join y %d, update %d %d %d\n", id_, 1,id(x[id_]),c[id_]);
                update(1,tot,1,1,id(x[id_]),c[id_]);
            } else {
                break;
            }
        }
        Nod tmp = query(1,tot,1,1,i);
        //printf("i=%d, mx=%d\n", i,tmp.mx);
        //ans = max(ans,tmp.mx);
        if (tmp.mx > ans) {
            ans = tmp.mx;
            ay = v[i-1];
            ax = v[tmp.pos-1];
        }
    }
    //brt();
    if(ans < 0) {
        for (int i=1;;i++){
            if(mp[i]==0) {
                printf("0\n%d %d %d %d",i,i,i,i); return 0;
            }
        }
    }
    printf("%lld\n%lld %lld %lld %lld\n", ans,ax,ax,ay,ay);
}