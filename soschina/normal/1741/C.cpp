#include <cstdio>
#include <iostream>
using namespace std;
const int N = 2001;

int t, n, a[N];

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int ans = n;
        for (int i = 1; i <= n; i++){
            int tar = 0;
            for (int j = 1; j <= i; j++)
                tar += a[j];
            int last = i, now = 0, len = i;
            for (int j = i + 1; j <= n; j++){
                now += a[j];
                if(now > tar)
                    break;
                else if(now == tar){
                    now = 0;
                    len = max(len, j - last);
                    last = j;
                }
            }
            if(now == 0)
                ans = min(ans, len);
        }
        printf("%d\n", ans);
    }
	return 0;
}