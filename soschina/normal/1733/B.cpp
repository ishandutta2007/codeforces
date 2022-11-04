#include <cstdio>
using namespace std;
const int N = 1e5 + 1;

int t, n, x, y, a[N], cnt[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d", &n, &x, &y);
        if(x && y || !x && !y){
            puts("-1");
            continue;
        }
        x = x | y;
        a[1] = 1;
        cnt[1] = 0;
        for (int i = 2; i <= n; i++){
            cnt[i] = cnt[i - 1] + 1;
            a[i] = a[i - 1];
            if(cnt[i] > x){
                cnt[i] = 1;
                a[i] = i;
            }

        }
        if(cnt[n] != x){
            puts("-1");
            continue;
        }
        for (int i = 2; i <= n; i++)
            printf("%d ", a[i]);
        putchar('\n');
    }
    return 0;
}