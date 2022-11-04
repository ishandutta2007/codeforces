#include <cstdio>
#include <iostream>
using namespace std;
const int N = 5001;

int n, a[N];
long long ans = 0x7fffffffffffffff;

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++){
        long long now = 0, cnt = 0;
        for (int j = i - 1; j > 0; j--){
            long long time = now / a[j] + 1;
            cnt += time;
            now = time * a[j];
        }
        now = 0;
        for (int j = i + 1; j <= n; j++){
            long long time = now / a[j] + 1;
            cnt += time;
            now = time * a[j];
        }
        ans = min(ans, cnt);
    }
    printf("%lld", ans);
    return 0;
}