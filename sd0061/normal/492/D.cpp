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
const int N = 1000005;

int n , X , Y;
int bel[N + N];
void work() {
    int i , j , k , x;
    scanf("%d%d%d",&n,&X,&Y);

    i = 1 , j = 1 , k = 0;
    while (i <= X || j <= Y) {
        if ((LL)i * Y == (LL)j * X) {
            bel[++ k] = 2;
            bel[++ k] = 2;
            ++ i , ++ j;
        } else if ((LL)i * Y < (LL)j * X) {
            bel[++ k] = 0;
            ++ i;
        } else {
            bel[++ k] = 1;
            ++ j;
        }
    }
    while (n --) {
        scanf("%d",&x);
        x %= (X + Y);
        if (!x) x = X + Y;
        if (bel[x] == 0)
            puts("Vanya");
        if (bel[x] == 1)
            puts("Vova");
        if (bel[x] == 2)
            puts("Both");
    }

}

int main() {
    work();
    return 0;
}