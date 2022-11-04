#include <cstdio>
using namespace std;
const int N = 1e5 + 2;

int n, m, a[N], x, y;
long long c[N], d[N];

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    a[n + 1] = 0;
    for (int i = 1; i <= n; i++){
        c[i] = a[i] - a[i - 1];
        if(c[i] < 0)
            c[i] = 0;
        c[i] += c[i - 1];
    }
    for (int i = n; i; i--){
        d[i] = a[i] - a[i + 1];
        if(d[i] < 0)
            d[i] = 0;
        d[i] += d[i + 1];
    }
    while(m--){
        scanf("%d%d", &x, &y);
        if(x < y){
            printf("%lld\n", d[x] - d[y]);
        }else{
            printf("%lld\n", c[x] - c[y]);
        }
    }
        return 0;
}