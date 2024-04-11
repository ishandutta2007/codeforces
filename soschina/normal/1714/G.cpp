#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2e5 + 1;

int t, n, fa[N], head[N], nxt[N], to[N], eid;
long long a[N], b[N];
void addedge(int u, int v){
    to[eid] = v;
    nxt[eid] = head[u];
    head[u] = eid++;
}

long long s[N], l;
int ans[N];

void dfs(int i){
    a[i] += a[fa[i]];
    b[i] += b[fa[i]];
    s[l++] = b[i];
    ans[i] = upper_bound(s + 1, s + l, a[i]) - s - 1;
    for (int e = head[i]; e; e = nxt[e])
        dfs(to[e]);
    l--;
}

int main(){
	scanf("%d", &t);
    while(t--){
        memset(head + 1, 0, sizeof(int) * n);
        eid = 1;
        scanf("%d", &n);
        for (int i = 2; i <= n; i++){
            scanf("%d%lld%lld", &fa[i], &a[i], &b[i]);
            addedge(fa[i], i);
        }
        dfs(1);
        for (int i = 2; i <= n; i++)
            printf("%d ", ans[i]);
        putchar('\n');
    }
	return 0;
}