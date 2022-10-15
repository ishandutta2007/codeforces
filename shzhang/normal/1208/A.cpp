#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        int a, b, n;
        scanf("%d%d%d", &a, &b, &n);
        if (n % 3 == 0) {
            printf("%d\n", a);
        } else if (n % 3 == 1) {
            printf("%d\n", b);
        } else {
            printf("%d\n", a^b);
        }
    }
    return 0;
}