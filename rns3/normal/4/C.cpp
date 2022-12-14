#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <string>
#include <map>
using namespace std;
#define N 100011

map <string, int> mp;

int n;
int vis[N];

int main(){
    //freopen("c.in", "r", stdin);
    mp.clear();
    int tot = 0;
    memset(vis, 0, sizeof(vis));
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        char t[33];
        scanf("%s", t);
        if(!mp[t]){
            mp[t] = ++tot;
            puts("OK");
            continue;
        }
        int d = mp[t];
        vis[d] ++;
        printf("%s%d\n", t, vis[d]);
    }
    return 0;
}