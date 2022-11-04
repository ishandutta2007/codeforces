#include <cstdio>
using namespace std;
const int N = 2e5 + 1;

int t, n, a[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        bool first = false;
        long long ans = 0;
        for (int i = 1; i < n; i++){
            scanf("%d", &a[i]);
            if(a[i])
                first = true;
            if(first && !a[i])
                ans++;
            ans += a[i];
        }
        scanf("%d", &a[n]);
        printf("%lld\n", ans);
    }
    return 0;
}