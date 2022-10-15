#include <cstdio>
#include <cstring>

using namespace std;

int n;
int a[200005];

char seq[200005];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    int l = 1; int r = n;
    int cur = 0;
    int id = 0;
    while (l <= r) {
        if (a[l] <= cur && a[r] <= cur) goto end_loop;
        if ((a[l] > cur && a[l] < a[r]) || (a[l] > cur && a[r] <= cur)) {
            seq[id++] = 'L'; cur = a[l]; l++;
        } else {
            seq[id++] = 'R'; cur = a[r]; r--;
        }
    }
end_loop:
    printf("%d\n", (int)strlen(seq));
    printf("%s", seq);
    return 0;
}