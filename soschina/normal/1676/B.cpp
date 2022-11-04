#include <cstdio>
#include <iostream>
using namespace std;
const int N = 51;

int t, n, a[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int minx = 0x7fffffff;
        for (int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            minx = min(minx, a[i]);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans += a[i] - minx;
        printf("%d\n", ans);
    }
    return 0;
}