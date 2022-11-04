#include <cstdio>
#include <iostream>
using namespace std;
const int N = 2e5 + 1;

int t, n, a[N];

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            a[i] = max(1, i - a[i] + 1);
        }
        int r = 1;
        long long ans = 0;
        for (int l = 1; l <= n; l++){
            while(r < n && l >= a[r + 1])
                r++;
            ans += r - l + 1;
        }
        printf("%lld\n", ans);
    }
	return 0;
}