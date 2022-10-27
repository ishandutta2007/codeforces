#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
const int N = 300000+10;
int q; map< pair<int,int>,int > last;
vector< pair<int,int> > edges[N<<2|1];
LL ans = 0;

void add(int l,int r,int rt,int L,int R,pair<int,int> v){
    if(L<=l&&r<=R) {
        edges[rt].push_back(v); return;
    }
    int mid=(l+r)>>1;
    if(L<=mid) add(l,mid,rt<<1,L,R,v);
    if(R >mid) add(mid+1,r,rt<<1|1,L,R,v);
}
int par[N<<1|1],szL[N<<1|1],szR[N<<1|1],CLOCK;
int pre[N*80];int *cur[N*80];
void change(int &x,int y){
    cur[CLOCK] = &x;
    pre[CLOCK] = x;
    x = y; CLOCK ++;
}
int find(int x){
    return par[x]==x?x:find(par[x]);
}
void merge(int x,int y){
    x=find(x), y=find(y);
    if(x==y) return;
    ans -= 1LL * szL[x] * szR[x];
    ans -= 1LL * szL[y] * szR[y];
    if(szL[x]+szR[x] > szL[y]+szR[y]) swap(x,y);
    change(par[x], y);
    change(szL[y], szL[y] + szL[x]);
    change(szR[y], szR[y] + szR[x]);
    //printf("x=%d, par=%d (%d,%d)\n", x,y,szL[y],szR[y]);
    ans += 1LL * szL[y] * szR[y];
    //printf("ans=%d\n", ans);
}
void vanishment(){
    --CLOCK;
    //printf("%d -> %d\n", *cur[CLOCK],pre[CLOCK]);
    (*cur[CLOCK]) = pre[CLOCK];
}
void solve(int l,int r,int rt){
    int mid=(l+r)>>1;
    int now = CLOCK; LL tmp=ans;
    //printf("solve %d %d %d\n", l,r,rt);
    for(auto p: edges[rt]) {
        /*
        if(find(p.first) != find(p.second))
            printf("Merge %d %d\n", p.first,p.second-N);
        */
        merge(p.first,p.second);
    }
    if(l==r){   
        printf("%lld ", ans); 
    }  else {
        solve(l,mid,rt<<1);
        solve(mid+1,r,rt<<1|1);
    }
    //printf("taopao %d %d %d\n", l,r,rt);
    //printf("CLOCK=%d, now=%d\n", CLOCK,now);
    while(CLOCK != now) vanishment(); 
    ans=tmp;
    //printf("out %d %d %d\n", l,r,rt);
}
int main() {
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        int x,y; scanf("%d%d",&x,&y); y=y+N;
        if(last[make_pair(x,y)]) {
            //printf("add %d %d (%d,%d)\n", last[make_pair(x,y)], i-1, x, y-N);
            add(1,q,1,last[make_pair(x,y)],i-1,make_pair(x,y));
            //printf("done\n");
            last[make_pair(x,y)]=0;
        } else {
            last[make_pair(x,y)]=i;
        }
    }
    for(auto p: last) {
        if(p.second) {
            //printf("add %d %d (%d,%d)\n", p.second,q,p.first.first,p.first.second-N);
            add(1,q,1,p.second,q,p.first);
        }
    }
    for(int i=1;i<=N;i++){
        par[i]=i; par[i+N]=i+N;
        szL[i]=1, szR[i+N]=1;
    }
    solve(1,q,1);
}