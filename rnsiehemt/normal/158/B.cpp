#include <cstdio>
#include <algorithm>

int N;
int a[5];
int q;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int b; scanf("%d", &b);
        a[b]++;
    }
    q = a[4];
    q += a[3];
    a[1] = std::max(0, a[1]-a[3]);
    q += a[2]/2;
    a[2] = a[2]%2;
    if (a[2]) {
        q++;
        a[1] = std::max(0, a[1]-2);
    }
    q += (a[1]+3)/4;
    printf("%d\n", q);
}