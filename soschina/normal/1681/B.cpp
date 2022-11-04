#include <cstdio>
using namespace std;
const int N = 2e5 + 1;

int t, n, a[N], m, b[N];

int main(){
    scanf("%d", &t);;
    while(t--){
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        scanf("%d", &m);
        for (int i = 1; i <= m; i++){
            scanf("%d", &b[i]);
            b[i] = n - b[i];
        }
        int now = 1;
        for (int i = m; i; i--){
            if(now <= b[i])
                now += n - b[i];
            else
                now -= b[i];
        }
        printf("%d\n", a[now]);
    }
    return 0;
}