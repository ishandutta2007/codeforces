#include <cstdio>
using namespace std;
const int N = 1e5 + 1;

int t, n, a[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for (int i = 0; i < n; i += 2){
            a[n - i] = n - i - 1;
            a[n - i - 1] = n - i;
        }
        if(n & 1)
            a[1] = 1;
        for (int i = 1; i <= n; i++)
            printf("%d ", a[i]);
        putchar('\n');
    }
    return 0;
}