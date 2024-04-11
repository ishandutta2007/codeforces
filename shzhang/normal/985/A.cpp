#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <cstdlib>

using namespace std;

int n;
int a[60];

int absolute(int v)
{
    return v > 0 ? v : -v;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n / 2; i++) {
        scanf("%d", a + i);
    }
    sort(a + 1, a + n / 2 + 1);
    int blackans = 0;
    int whiteans = 0;
    for (int i = 1; i <= n / 2; i++) {
        blackans += absolute(i * 2 - 1 - a[i]);
        whiteans += absolute(i * 2 - a[i]);
    }
    printf("%d", min(blackans, whiteans));
    return 0;
}