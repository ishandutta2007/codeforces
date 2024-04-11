#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 200000 + 10;
typedef long long LL;

int main() {
    int t; scanf("%d", &t);
    while (t --) {
        LL x, y; scanf("%lld%lld", &x, &y);
        if (x - y == 1) printf("NO\n");
        else printf("YES\n");
    }
}