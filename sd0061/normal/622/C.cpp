#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <unordered_map>
using namespace std;
typedef long long LL;
const int N = 200005;
const int Q = 998244353;

int n , m;
int a[N] , nxt[N];

void work() {
    scanf("%d%d" , &n , &m);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &a[i]);
    }
    for (int i = n ; i > 0 ; -- i) {
        if (i == n || a[i] != a[i + 1])
            nxt[i] = i + 1;
        else
            nxt[i] = nxt[i + 1];
    }
    while (m -- ) {
        int l , r , x;
        scanf("%d%d%d" , &l , &r , &x);
        int i = l; bool flag = 0;
        while (i <= r) {
            if (a[i] != x) {
                flag = 1;
                break;
            }
            i = nxt[i];
        }
        printf("%d\n" , flag ? i : -1);
    }
    
}
 
int main() {
    work();
    return 0;
}