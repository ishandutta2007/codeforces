#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int a[400010], b[400010];
int v[400010];
bool vis[400010];
int n;
const int MOD = 1e9 + 7;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
        for (int i = 1; i <= n; i++) scanf("%d",&b[i]);
        for (int i = 1; i <= n; i++) v[a[i]] = b[i];
        for (int i = 1; i <= n; i++) vis[i] = false;
        int com = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                //printf("into %d\n",i);
                int sz = 0;
                for (int j = i; !vis[j]; j = v[j]) {
                    //printf("vis %d\n",j);
                    vis[j] = true;
                    sz++;
                }
                if (sz > 1) {
                    com++;
                }
            }
        }
        int ans = 1;
        for (int i = 1; i <= com; i++) ans = ans * 2 % MOD;
        printf("%d\n",ans);
    }
}