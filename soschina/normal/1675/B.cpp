#include <cstdio>
using namespace std;

int t, n, a[31];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int ans = 0;
        for (int i = n - 1; i > 0; i--){
            while(a[i] && a[i] >= a[i + 1]){
                ans++;
                a[i] /= 2;
            }
            if(a[i] == a[i + 1])
                ans = 0x80000000;
        }
        printf("%d\n", ans < 0 ? -1 : ans);
    }
    return 0;
}