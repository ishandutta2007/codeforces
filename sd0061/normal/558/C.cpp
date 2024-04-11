#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <cctype>
#include <unordered_map>
using namespace std;
typedef long long LL;
const int N = 100005;
int n , a[N];
int d[N] , t[N] , res[N] , cnt[N];
void work() {
    scanf("%d" , &n);
    for (int i = 1 ; i <= n ; ++ i) {
        int x;
        scanf("%d" , &x);
        queue<int> Q;
        Q.push(x);
        t[x] = i;
        d[x] = 0;
        while (!Q.empty()) {
            x = Q.front(); Q.pop();
            ++ cnt[x];
            res[x] += d[x];
            if (t[x / 2] != i) {
                t[x / 2] = i;
                d[x / 2] = d[x] + 1;
                Q.push(x / 2);
            }
            if (x + x < N && t[x + x] != i) {
                t[x + x] = i;
                d[x + x] = d[x] + 1;
                Q.push(x + x);
            }
        }
    }
    int ans = 1 << 30;
    for (int i = 0 ; i < N ; ++ i)
        if (cnt[i] == n)
            ans = min(ans , res[i]);
    cout << ans << endl;   
}

int main() {
    work();
    return 0;
}