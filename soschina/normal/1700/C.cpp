#include <cstdio>
#include <iostream>
using namespace std;
const int N = 2e5 + 1;

int t, n;
long long a[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        long long ans = 0;
        for (int i = n; i > 1; i--)
            a[i] -= a[i - 1];
        for (int i = n; i > 1; i--){
            if(a[i] > 0)
                ans += a[i];
            else if(a[i] < 0){
                a[1] += a[i];
                ans -= a[i];
            }
        }
        ans += abs(a[1]);
        printf("%lld\n", ans);
    }
    return 0;
}