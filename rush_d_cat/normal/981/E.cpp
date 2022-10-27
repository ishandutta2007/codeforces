#include <iostream>
#include <algorithm>
using namespace std;
const int N = 10002;
int n,m,f[N];
struct Q{int l,r,v;}q[N];
bool cmp(Q A, Q B) {return A.l < B.l;}
int main() {    
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].v);
    sort(q+1,q+1+m,cmp);
    f[0]=N;
    for(int i=1;i<=m;i++)
    for(int j=n;j>=q[i].v;j--) {
        if(f[j-q[i].v]>=q[i].l)
        f[j]=max(f[j],min(f[j-q[i].v], q[i].r));
    }
    int cnt=0;
    for(int i=1;i<=n;i++) if(f[i]) cnt++;
    printf("%d\n", cnt);
    for(int i=1;i<=n;i++) if(f[i]) printf("%d ", i);
}