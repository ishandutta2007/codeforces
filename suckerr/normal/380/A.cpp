#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 111111;
const int LIMIT = 100005;

int a[N], top = 0;
long long length[N];
int mark[N], cc[N], ll[N], type[N];

int main() {
    int m;
    scanf("%d", &m);
    for(int i = 1; i <= m; i++) {
        scanf("%d", &type[i]);
        if (type[i] == 1) {
            scanf("%d", &mark[i]);
            if (top < LIMIT)
                a[++top] = mark[i];
            length[i] = length[i - 1] + 1;
        } else {
            scanf("%d %d", &ll[i], &cc[i]);
            for(int k = 1; k <= cc[i] && top < LIMIT; k++)
                for(int l = 1; l <= ll[i] && top < LIMIT; l++) {
                    a[++top] = a[l];
                }
            length[i] = length[i - 1] + 1LL * cc[i] * ll[i];
        }
    }
    
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        long long q;
        scanf("%I64d", &q);
        if (q == 4)
            q = 4;
        int pos = lower_bound(length + 1, length + m + 1, q) - length;
        if (type[pos] == 1) {
            printf("%d ", mark[pos]);
        } else {
            q -= length[pos - 1];
            q %= ll[pos];
            if (q == 0)
                q = ll[pos];
            printf("%d ", a[q]);
        }
    }
    printf("\n");
    return 0;
}