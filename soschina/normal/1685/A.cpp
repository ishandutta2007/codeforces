#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5 + 1;

int t, n, a[N], b[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        if(n & 1){
            puts("NO");
            continue;
        }
        sort(a + 1, a + 1 + n);
        int l = n / 2, r = n;
        for (int i = 1; i <= n; i += 2){
            b[i] = a[r--];
            b[i + 1] = a[l--];
        }
        bool flag = true;
        for (int i = 1; i <= n; i++)
            if(b[i] == b[i % n + 1])
                flag = false;
        if(!flag)
            puts("NO");
        else{
            puts("YES");
            for (int i = 1; i <= n; i++)
                printf("%d ", b[i]);
            putchar('\n');
        }
    }
    return 0;
}