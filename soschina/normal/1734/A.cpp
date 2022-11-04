#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 301;

int t, n, a[N];

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        sort(a + 1, a + 1 + n);
        int ans = 0x7fffffff;
        for (int i = 2; i < n; i++){
            ans = min(ans, abs(a[i] - a[i - 1]) + abs(a[i] - a[i + 1]));
        }
        printf("%d\n", ans);
    }
	return 0;
}