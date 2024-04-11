#include <cstdio>
using namespace std;
const int N = 2.5e5 + 1;

int t, n, a[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        if(n == 1){
            scanf("%d", &a[1]);
            puts("0");
            continue;
        }
        int now = 1, mx = 1, mn = 1, ans = 0;
        scanf("%d", &a[1]);
        for (int i = 2; i <= n; i++){
            scanf("%d", &a[i]);
            if(a[i] > a[mx]){
                if(a[mn] < a[now] && a[i] > a[now]){
                    ans++;
                    now = mn;
                }
                mx = i;
            }
            else if(a[i] < a[mn]){
                if(a[i] < a[now] && a[mx] > a[now]){
                    ans++;
                    now = mx;
                }
                mn = i;
            }
        }
        now = mx = mn = n;
        for (int i = n - 1; i >= 1; i--){
            if(a[i] > a[mx]){
                if(a[mn] < a[now] && a[i] > a[now]){
                    ans++;
                    now = mn;
                }
                mx = i;
            }
            else if(a[i] < a[mn]){
                if(a[i] < a[now] && a[mx] > a[now]){
                    ans++;
                    now = mx;
                }
                mn = i;
            }
        }
        printf("%d\n", ans + 1);
    }
    return 0;
}