#include <iostream>
using namespace std;
const int N = 1e5+2;
int n,a[N],tot,cnt[N];
int u[N],v[N];

int main() {
    scanf("%d",&n);
    for(int i=1;i<n;i++) {
        scanf("%d%d",&u[i],&v[i]);
    }

    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) {
        if(a[u[i]] != a[v[i]]) {
            cnt[u[i]] ++, cnt[v[i]] ++; tot ++;
        }
    }
    for(int i=1;i<=n;i++) {
        if(cnt[i]==tot) return !printf("YES\n%d\n",i);
    }
    printf("NO\n");
}