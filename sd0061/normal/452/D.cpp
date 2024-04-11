#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxl = 100005;

int a[Maxl], b[Maxl], c[Maxl];
int ac, bc, cc;
int k, n1, n2, n3, t1, t2, t3;
int lst;

int main()
{
    scanf("%d %d %d %d %d %d %d", &k, &n1, &n2, &n3, &t1, &t2, &t3);
    for (int i = 0; i < k; i++) {
        int entr = max(max(a[ac], b[bc]), c[cc]);
        lst = entr + t1 + t2 + t3;
        a[n1 + ac++] = entr + t1; b[n2 + bc++] = entr + t2; c[n3 + cc++] = entr + t3;
    }
    printf("%d\n", lst);
    return 0;
}