#include <stdio.h>
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define N 5002
#define inf 1000000000

int d[N], mx[N];
int a[N];
int id[N], l[N], r[N], p[N];

int main() {
    int n, m, i, j, Max;
    scanf("%d %d", &n, &m);
    for (i=1; i<=n; i++) mx[i]=inf;
    for (i=0; i<m; i++) {
        scanf("%d %d %d %d", id+i, l+i, r+i, p+i);
        if (id[i]==1) {
            for (j=l[i]; j<=r[i]; j++) d[j]+=p[i];
        } else {
            for (j=l[i]; j<=r[i]; j++) {
                mx[j]=min(mx[j], p[i]-d[j]);
            }
        }
    }
    for (i=1; i<=n; i++) a[i]=mx[i];
    for (i=0; i<m; i++) {
        if (id[i]==1) {
            for (j=l[i]; j<=r[i]; j++) a[j]+=p[i];
        } else {
            Max=-inf;
            for (j=l[i]; j<=r[i]; j++) Max=max(a[j], Max);
            if (Max!=p[i]) {
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    for (i=1; i<=n; i++) printf("%d%s", mx[i], (i==n)?"\n":" ");
}