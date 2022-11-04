#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
const int N = 1.5e5 + 1;

int t, n, q, x, a[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        sort(a + 1, a + 1 + n, greater<int>());
        for (int i = 2; i <= n; i++)
            a[i] += a[i - 1];
        while(q--){
            scanf("%d", &x);
            int p = lower_bound(a + 1, a + 1 + n, x) - a;
            if(p == n + 1)
                puts("-1");
            else
                printf("%d\n", p);
        }
    }
    return 0;
}