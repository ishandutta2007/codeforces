#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
int t,n,m,a[N],b[N],p[N];
int bit[N];
void add(int pos){
    while(pos<N){
        bit[pos]++; pos+=pos&-pos;
    }
}
int sum(int pos){
    int ans=0;
    while(pos>0){
        ans+=bit[pos]; pos-=pos&-pos;
    }
    return ans;
}
int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]); p[a[i]]=i;
        }
        for(int i=1;i<=m;i++)scanf("%d",&b[i]);
        int las=0;
        LL ans = 0;
        memset(bit,0,sizeof(bit));
        for(int i=1;i<=m;i++){
            if(p[b[i]] > las){
                ans = ans + 2 * (p[b[i]] - sum(p[b[i]])) - 1;
                las = p[b[i]];
            } else {
                ans ++;
            }
            add(p[b[i]]);
        }
        printf("%lld\n", ans);
    }
}