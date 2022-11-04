#include <cstdio>
using namespace std;
const int N = 2e5 + 1;

int t, n, k, a[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        if(k == 1){
            printf("%d\n", (n - 1) / 2);
            continue;
        }
        int cnt = 0;
        for (int i = 2; i < n; i++)
            if(a[i] > a[i - 1] + a[i + 1])
                cnt++;
        printf("%d\n", cnt);
    }
    return 0;
}