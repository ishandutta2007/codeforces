#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int N = 300000 + 10;
int t;
int n,a[N],b[N],aa[N],bb[N];

int mn[N<<2];
void update(int l,int r,int rt,int pos,int x) {
    if(l==r) {
        mn[rt]=x; return;
    }
    int mid=(l+r)>>1;
    if(pos<=mid) update(l,mid,rt<<1,pos,x);
    else update(mid+1,r,rt<<1|1,pos,x);
    mn[rt]=min(mn[rt<<1],mn[rt<<1|1]);
}
int query(int l,int r,int rt,int L,int R){
    if(L<=l&&r<=R) return mn[rt];
    int mid=(l+r)>>1,ans=1e9;
    if(L<=mid) ans=min(query(l,mid,rt<<1,L,R),ans);
    if(R >mid) ans=min(query(mid+1,r,rt<<1|1,L,R),ans);
    return ans;
}
queue<int> v[N];
int main(){
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);aa[i]=a[i]; while(v[a[i]].size()) v[a[i]].pop();
        }
        for(int i=1;i<=n;i++) {
            v[a[i]].push(i);
        }
        for(int i=1;i<=n;i++) {
            scanf("%d",&b[i]);bb[i]=b[i];
        }
        sort(aa+1,aa+1+n); sort(bb+1,bb+1+n);
        bool flag=0;
        for(int i=1;i<=n;i++){
            if(aa[i]!=bb[i]) {
                printf("NO\n"); flag=1; break;
            }
        }
        if(flag) continue;
        bool gg=0;
        for(int i=1;i<=n;i++) update(1,n,1,i,a[i]);
        for(int i=1;i<=n;i++) {
            int pos=v[b[i]].front(); v[b[i]].pop();
            int mn=query(1,n,1,1,pos);
            //printf("pos=%d, mn=%d\n", pos,mn);
            if(mn==b[i]){
                update(1,n,1,pos,1e9);
            } else {
                gg=1;
            }
        }
        printf("%s\n", gg?"NO":"YES");
    }
}