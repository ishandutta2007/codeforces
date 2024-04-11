#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

int a[200005];
int n;

int main()
{
    scanf("%d", &n);
    int total = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        total += a[i];
    }
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        cur += a[i];
        if (cur * 2 >= total) {
            printf("%d", i); return 0;
        }
    }
    return 0;
}