#include <cstdio>
#include <iostream>
using namespace std;

int t, n, rem[46], ans;
bool used[10];

void dfs(int i, int s, int now){
    if(now > ans)
        return;
    if(!s){
        ans = min(ans, now);
        return;
    }
    for (int j = !i; j <= min(s, 9); j++)
        if(!used[j]){
            used[j] = true;
            dfs(i + 1, s - j, now * 10 + j);
            used[j] = false;
        }
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        if(rem[n]){
            printf("%d\n", rem[n]);
            continue;
        }
        ans = 0x7fffffff;
        dfs(0, n, 0);
        printf("%d\n", rem[n] = ans);
    }
    return 0;
}