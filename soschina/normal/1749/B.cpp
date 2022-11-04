#include <cstdio>
#include <iostream>
using namespace std;
const int N = 2e5 + 1;

int t, n, a[N], b[N];

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        long long ans = 0;
        int maxb = 0;
        for (int i = 1; i <= n; i++){
                scanf("%d", &a[i]);
                ans += a[i];
        }
        for(int i = 1; i <= n; i++){
            scanf("%d", &b[i]);
            ans += b[i];
            maxb = max(maxb, b[i]);
        }
        printf("%lld\n", ans - maxb);
    }
	return 0;
}