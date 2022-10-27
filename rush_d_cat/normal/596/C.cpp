#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 100000 + 10;
struct Nod {
    int x,y,id,ans;
    bool operator <(const Nod & o) const {
        return x+y < o.x+o.y;
    }
} nod[N];
bool cmp(Nod A, Nod B) {
    if(A.x==B.x) return A.y<B.y;
    return A.x<B.x;
}
int n,a[N<<1],res[N<<1];
int bit[N<<1],xx[N<<1],yy[N<<1];
void add(int x,int id) {
    while(x<N) {
        bit[x]=max(bit[x],id); x+=(x&(-x));
    }
}
int query(int x) {
    int ans=0; while(x) {ans=max(ans,bit[x]); x-=x&(-x);}
    return ans;
}
int main() {
    scanf("%d",&n);
    priority_queue<Nod> q[2*N]; 
    for(int i=1;i<=n;i++) {
        scanf("%d%d",&nod[i].x,&nod[i].y); nod[i].id=i;
        q[nod[i].y-nod[i].x+N].push(nod[i]);
    }
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    //printf("ok\n");
    for(int i=n;i>=1;i--) {
        if(q[a[i]+N].size()==0) return !printf("NO\n");
        Nod now = q[a[i]+N].top(); q[a[i]+N].pop();
        res[now.id] = i;
    }
    for(int i=1;i<=n;i++) nod[i].ans = res[nod[i].id];
    //printf("ok\n");
    sort(nod+1,nod+1+n,cmp);

    bool ok = 1;
    for(int i=1;i<=n;i++) {
        if(query(nod[i].y+1)>nod[i].ans) ok=0;
        add(nod[i].y+1,nod[i].ans);
    }
    if(ok==0) return !printf("NO\n");
    printf("YES\n");
    for(int i=1;i<=n;i++) xx[nod[i].ans]=nod[i].x, yy[nod[i].ans]=nod[i].y;
    for(int i=1;i<=n;i++) printf("%d %d\n", xx[i],yy[i]);

}