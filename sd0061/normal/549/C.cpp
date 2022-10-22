#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;

int n , K;

int dfs(int x , int y) {
    if (x + y == K) {
        int p = n - x - y;
        return (x & 1) ^ (p & 1);
    } else if (x + y <= K + 10) {
        int r = 1;
        if (x) r &= dfs(x - 1 , y);
        if (y) r &= dfs(x , y - 1);
        return r ^= 1;
    } else {
        if (!x || !y) {
            int r = 1;
            if (x) r &= dfs(x - 1 , y);
            if (y) r &= dfs(x , y - 1);
            return r ^= 1;
        }
        return dfs(x - 1 , y - 1);
    }
}

void work() {
    int i , j , x , y;
    scanf("%d%d" , &n , &K);
    x = y = 0;
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d" , &j);
        if (j & 1)
            ++ x;
        else
            ++ y;
    }
    cout << (dfs(x , y) ? "Stannis" : "Daenerys") << endl;
}

int main() {
    work();
    return 0;
}