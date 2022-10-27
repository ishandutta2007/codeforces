#include <iostream>
#include <vector>
using namespace std;
const int N = 1000000 + 10;
typedef long long LL;
vector< pair< pair<int,int>, int > > vec[1000000+10];
int n,k,m;
LL sum[N<<2],val[N<<2];
void pushup(int rt){
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
    val[rt]=val[rt<<1]+val[rt<<1|1];
}
void update(int l,int r,int rt,int pos,int x){
    if(l==r){
        sum[rt] += x; val[rt] += (LL)x*pos; return;
    }
    int mid=(l+r)>>1;
    if(pos<=mid) update(l,mid,rt<<1,pos,x);
    else update(mid+1,r,rt<<1|1,pos,x);
    pushup(rt);
}
LL query(int rt,int l,int r,int k){
    if(l==r) return min((LL)k,sum[rt]) * l;
    int mid=(l+r)>>1;
    if(sum[rt<<1] >= k) return query(rt<<1,l,mid,k);
    return query(rt<<1|1,mid+1,r,k-sum[rt<<1]) + val[rt<<1];
}
int main() {
    scanf("%d%d%d",&n,&k,&m);
    for(int i=1;i<=m;i++) {
        int l,r,c,p; scanf("%d%d%d%d",&l,&r,&c,&p);
        vec[l].push_back(make_pair(make_pair(c,p),+1));
        vec[r+1].push_back(make_pair(make_pair(c,p),-1));
    }
    LL ans=0; 
    for(int i=1;i<=n;i++) {
        for(auto p: vec[i]) {
            if(p.second == 1)
                update(1,1000000,1, p.first.second,+ p.first.first);
            else 
                update(1,1000000,1, p.first.second,- p.first.first);
        }
        ans += query(1,1,1000000,k);
    }
    cout<<ans<<endl;
}