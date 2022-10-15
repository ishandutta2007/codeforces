#include <cstdio>
#include <vector>

using namespace std;

char as[200005];
int a[200005];
int f[10];

int main()
{
    int n;
    scanf("%d", &n);
    scanf("%s", as + 1);
    for (int i = 1; i <= 9; i++) scanf("%d", f + i);
    for (int i = 1; i <= n; i++) a[i] = as[i] - '0';
    int start = 1;
    while (start <= n) {
        if (f[a[start]] > a[start]) break;
        start++;
    }
    if (start > n) {
        printf("%s", as + 1); return 0;
    }
    int end = start + 1;
    while (end <= n) {
        if (f[a[end]] < a[end]) break;
        end++;
    }
    for (int i = start; i < end; i++) a[i] = f[a[i]];
    for (int i = 1; i <= n; i++) printf("%d", a[i]);
    return 0;
}