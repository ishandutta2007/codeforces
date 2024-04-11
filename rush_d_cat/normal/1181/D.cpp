#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 500000 + 10;
int n,m,q;
int a[N];
LL cnt[N],res[N]; int cas;
vector<int> c[N];
vector< pair<int,int> > vec;
vector<int> vec2[N];

int nod[N<<2];
void update(int l,int r,int rt,int pos) {
    if(l==r) {
        nod[rt]++; return;
    }
    int mid=(l+r)>>1;
    if(pos<=mid) update(l,mid,rt<<1,pos);
    else update(mid+1,r,rt<<1|1,pos);
    nod[rt]=nod[rt<<1]+nod[rt<<1|1];
}
int query(int l,int r,int rt,int k) {
    //printf("[%d, %d] %d\n", l,r,k);
    if(l==r) return l;
    int mid=(l+r)>>1;
    if(nod[rt<<1] >= k) return query(l,mid,rt<<1,k);
    return query(mid+1,r,rt<<1|1,k-nod[rt<<1]);
}
struct que {
    int k,id;
}; 
std::vector<que> v[N];
int main() {
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]), c[a[i]].push_back(i);
    for(int i=1;i<=m;i++) cnt[c[i].size()]++;
    for(int i=1;i<=m;i++) {
        vec.push_back(make_pair(c[i].size(),i));
        vec2[c[i].size()].push_back(i);
    }
    sort(vec.begin(),vec.end());
    for(int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
    for(int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
    cnt[n+1]=1e18;
//for(int i=0;i<=n+1;i++) printf("# %lld\n", cnt[i]);
    while(q--){
        LL x; scanf("%lld",&x); x-=n;
        int p=lower_bound(cnt,cnt+2+n,x)-cnt;
        if(p==n+1) {
            x-=cnt[n];
            x%=m; if(x==0) x=m;
            res[++cas]=x;
        } else {
            if(p) x-=cnt[p-1];
            v[p].push_back((que){x,++cas});
        }
    }
    for(int i=0;i<=n;i++){
        for(auto p: vec2[i]) update(1,m,1,p);
        for(auto p: v[i]) res[p.id] = query(1,m,1,p.k);
    }
    for(int i=1;i<=cas;i++) printf("%d\n",res[i]);
}