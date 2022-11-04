#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1 << 17 | 1;

int t, n, u, v, head[N], nxt[N << 1], to[N << 1], eid;
int tagp[N], tage[N];
void addedge(int u, int v){
    to[eid] = v;
    nxt[eid] = head[u];
    head[u] = eid++;
}

int cnt;
void dfs(int i, int pre, bool flip){
    for (int e = head[i]; e; e = nxt[e])
        if(to[e] != pre){
            if(flip){
                tage[e >> 1] = cnt;
                tagp[to[e]] = cnt ^ n;
            }else{
                tage[e >> 1] = cnt ^ n;
                tagp[to[e]] = cnt;
            }
            cnt++;
            dfs(to[e], i, flip ^ 1);
        }
}

int main(){
	scanf("%d", &t);
    while(t--){
        cnt = 1;
        eid = 2;
        memset(head + 1, 0, sizeof(int) * n);
        scanf("%d", &n);
        n = 1 << n;
        for (int i = 1; i < n; i++){
            scanf("%d%d", &u, &v);
            addedge(u, v);
            addedge(v, u);
        }
        tagp[1] = n;
        dfs(1, 0, 0);
        puts("1");
        for (int i = 1; i <= n; i++)
            printf("%d ", tagp[i]);
        putchar('\n');
        for (int i = 1; i < n; i++)
            printf("%d ", tage[i]);
        putchar('\n');
    }
	return 0;
}