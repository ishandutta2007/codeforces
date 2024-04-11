#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int N=300000+10;
int sum[N<<2];
void update(int l,int r,int rt,int pos,int x){
    if(l==r){
        sum[rt]=x; return;
    }
    int mid=(l+r)>>1;
    if(pos<=mid)update(l,mid,rt<<1,pos,x);
    else update(mid+1,r,rt<<1|1,pos,x);
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
int query(int l,int r,int rt,int L,int R){
    if(L<=l&&r<=R)return sum[rt];
    int mid=(l+r)>>1,ans=0;
    if(L<=mid)ans+=query(l,mid,rt<<1,L,R);
    if(R >mid)ans+=query(mid+1,r,rt<<1|1,L,R);
    return ans;
}
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
int n,L[N],R[N],px[N],py[N],ans[N];
pair<int,int> a[N]; int tot;
vector< pair<int,int> > v[N];
map< pair<int,int>, int > pre;
void read(int id){
    //printf("id=%d\n", id);
    int k; scanf("%d",&k);
    for(int i=1;i<=k;i++){
        scanf("%d%d",&px[i],&py[i]);
    }
    L[id]=tot+1;
    px[k+1]=px[1], py[k+1]=py[1];
    for(int i=1;i<=k;i++){
        int dx=px[i+1]-px[i];
        int dy=py[i+1]-py[i];
        int g=gcd(dx,dy);
        g=abs(g);
        dx/=g,dy/=g;

        //printf("# %d %d\n", dx,dy);
        a[++tot]=make_pair(dx,dy);
    }
    R[id]=tot;
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)read(i);
    int q; scanf("%d",&q);
    for(int i=1;i<=q;i++){
        int l,r; scanf("%d%d",&l,&r);
        v[R[r]].push_back(make_pair(i,L[l]));
    }
    //printf("ok\n");
    for(int r=1;r<=tot;r++){
        if(pre[a[r]]) {
            //printf("!! (%d,%d)\n", a[r].first,a[r].second);
            //printf("update %d -1\n", pre[a[r]]);
            update(1,tot,1,pre[a[r]],0);
        }
        //printf("insert (%d, %d)\n", a[r].first,a[r].second);
        pre[a[r]]=r;
        //printf("update %d +1\n", pre[a[r]]);
        update(1,tot,1,pre[a[r]],+1);
        for(auto p: v[r]) {
            int l=p.second;
            int id=p.first;
            //printf("que %d %d\n", l,r);
            ans[id]=query(1,tot,1,l,r);
        }
    }
    for(int i=1;i<=q;i++)printf("%d\n", ans[i]);
}