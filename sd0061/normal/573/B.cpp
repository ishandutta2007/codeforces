#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 100005;
int n , a[N] ;
int cnt[N];
bool check(int p) {
    memset(cnt , 0 , sizeof(cnt));
    for (int i = 0 ; i <= n + 1 ; ++ i) {
        int x = p - a[i];
        if (x >= 0) {
            int L = max(1 , i - x);
            int R = min(n , i + x);
            ++ cnt[L] , -- cnt[R + 1];
        }
    }
    for (int i = 1 ; i <= n ; ++ i) {
        cnt[i] += cnt[i - 1];
        if (!cnt[i])
            return 1;
    }
    return 0;
}

int main() {
    scanf("%d" , &n);
    for (int i = 1 ; i <= n ; ++ i)
        scanf("%d" , &a[i]);
    int top = 0 , bot = 1e9 , m;
    while (top < bot) {
        m = top + bot + 1 >> 1;
        if (check(m))
            top = m;
        else
            bot = m - 1;
    }
    cout << top + 1 << endl;
    return 0;
}