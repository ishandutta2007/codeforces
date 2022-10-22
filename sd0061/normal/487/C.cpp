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
#include <bitset>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 100005;

int n;

int inv(int x) {
    return x == 1 ? 1 : (LL)(n - n / x) * inv(n % x) % n;
}

void work() {
    cin >> n;
    if (n == 1) {
        puts("YES\n1");
        return;
    }
    if (n == 4) {
        puts("YES\n1 3 2 4");
        return;
    }
    int i;
    for (i = 2 ; i * i <= n ; ++ i)
        if (n % i == 0)
            break;
    if (i * i <= n) {
        puts("NO");
        return;
    }
    puts("YES\n1");
    for (i = 2 ; i < n ; ++ i) {
        int x = (LL) i * inv(i - 1) % n;
        printf("%d\n" , x);
    }
    printf("%d\n" , n);
}

int main() {
    //freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}