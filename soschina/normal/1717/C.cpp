#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 2e5 + 1;

int t, n, a[N], b[N], id[N], vis[N];
bool flag;

bool cmp(int x, int y){
    return b[x] > b[y];
}

void dfs(int i){
    vis[i] = 1;
    if(a[i] > b[i])
        flag = false;
    else if(a[i] != b[i] && b[i] > a[i % n + 1] + 1){
        if(b[i] > b[i % n + 1] + 1 || vis[i % n + 1] == 1)
            flag = false;
        else if(!vis[i % n + 1])
            dfs(i % n + 1);
    }
    vis[i] = 2;
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int minb = 0x7fffffff;
        for (int j = 1; j <= n; j++){
            scanf("%d", &b[j]);
            if(b[j] < minb)
                minb = b[j];
            vis[j] = 0;
            id[j] = j;
        }
        for (int i = 1; i <= n; i++)
            if(minb > a[i])
                a[i] = minb;
        sort(id + 1, id + 1 + n, cmp);
        flag = true;
        for (int i = 1; i <= n && flag; i++)
            if(!vis[id[i]])
                dfs(id[i]);
        puts(flag ? "YES" : "NO");
    }
    return 0;
}