#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int T,n,las[N];
int main() {
    scanf("%d",&T);
    while(T--){
        scanf("%d", &n);
        int ans = 1e9;
        for (int i=1;i<=n;i++)las[i]=0;
        for (int i=1;i<=n;i++) {
            int x; scanf("%d", &x);
            if (las[x]) ans = min(ans, i - las[x] + 1);
            las[x] = i;
        }
        printf("%d\n", ans == 1e9?-1:ans);
    }
}