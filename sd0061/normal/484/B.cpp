#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 1000005;
int n , R[N];
bool vis[N];

int main() {
    int i , j , x;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d",&x);
        vis[x] = 1;
    }
    R[0] = -1;
    for (i = 1 ; i <= 1000000 ; ++ i) {
        if (vis[i])
            R[i] = i;
        else
            R[i] = R[i - 1];
    }
    int ans = 0;
    for (i = 1 ; i <= 1000000 ; ++ i) {
        if (!vis[i]) continue;
        for (j = i + i ; j <= 1000000 ; j += i) {
            if (~R[j - 1])
                ans = max(ans , R[j - 1] % i);
        }
        j = 1000000;
        if (~R[j])
            ans = max(ans , R[j] % i);
    }
    printf("%d\n" , ans);
    return 0;
}