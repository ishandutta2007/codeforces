#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 100005;
int n , m;
vector<int> e[N];
int c[N] , cnt[3];

bool dfs(int x , int C) {
    if (c[x] && c[x] != C) return 0;
    if (c[x] && c[x] == C) return 1;
    c[x] = C;
    ++ cnt[C];
    for (auto &y : e[x])
        if (!dfs(y , 3 - C))
            return 0;
    return 1;
}
void work() {
    scanf("%d%d" , &n , &m);
    for (int i = 0 ; i < m ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    LL res1 = 0 , res2 = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        if (!c[i]) {
            cnt[1] = cnt[2] = 0;
            if (!dfs(i , 1)) {
                puts("0 1");
                return;
            }
            res1 += (LL)cnt[1] * (cnt[1] - 1) / 2;
            res1 += (LL)cnt[2] * (cnt[2] - 1) / 2;            
            if (cnt[1] == 1 && cnt[2] == 1)
                res2 += n - 2;
        }
    }
    if (res1)
        printf("1 %lld\n" , res1);
    else if (!m) {
        printf("3 %lld\n" , (LL)n * (n - 1) * (n - 2) / 6);    
    } else {
        printf("2 %lld\n" , res2);
    }

}

int main() {
    work();
    return 0;
}