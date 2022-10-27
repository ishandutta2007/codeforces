#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;

const int N = 6000000 + 10;

int n,q,a[N];
LL m;
int ans[N][3];
int main() {
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int head=1,tail=n;
    int mx=0; for(int i=1;i<=n;i++) mx=max(mx,a[i]);
    memset(ans,-1,sizeof(ans));
    int las=0;
    for(int i=1;;i++){
        if(a[head] == mx) break;
        las = i;
        int mx=max(a[head],a[head+1]);
        int mn=min(a[head],a[head+1]);
        ans[i][0]=a[head],ans[i][1]=a[head+1];
        a[++head]=mx; a[++tail]=mn;
    } 
    while(q--){
        scanf("%lld",&m);
        if(m<N && ans[m][0]!=-1) {
            printf("%d %d\n", ans[m][0],ans[m][1]);
        } else {
            int x = (m-las)%(n-1); if(x==0) x=n-1;
            printf("%d %d\n", mx, a[head+x]);
        }
    }
}