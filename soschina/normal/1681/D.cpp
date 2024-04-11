#include <cstdio>
#include <iostream>
using namespace std;

int n, ans = 0x7fffffff;
long long x;
__int128 m, y;

void dfs(__int128 x, int step){
    int cnt = 0;
    bool bits[10] = {};
    __int128 tmp = x;
    while(tmp){
        cnt++;
        bits[tmp % 10] = 1;
        tmp /= 10;
    }
    if(ans - step <= n - cnt)
        return;
    if(cnt >= n){
        ans = min(ans, step);
        return;
    }
    for (int i = 9; i >= 2; i--)
        if(bits[i]) dfs(x * i, step + 1);
}

int main(){
    scanf("%d%lld", &n, &x);
    dfs(x, 0);
    printf("%d", ans == 0x7fffffff ? -1 : ans);
    return 0;
}