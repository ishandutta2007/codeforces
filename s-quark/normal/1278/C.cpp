#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int INF = 1<<20;
const int MAXN = 112345;

int a[MAXN*2];
int _t[MAXN*2];
int *t = _t+MAXN;

int main(){
    int T;
    int i0;
    scanf("%d", &T);
    for(i0 = 0; i0 < T; i0++) {
        int n;
        int i;
        int cnt;
        scanf("%d", &n);
        for(i = 0; i < 2*n; i++)
            scanf("%d", &a[i]);
        
        for(i = -n; i <= n; i++)
            t[i] = INF;
        cnt = 0;
        for(i = 0; i <= n; i++) {
            t[cnt] = n-i;
            if(i == n)
                break;
            if(a[i] == 1)
                cnt++;
            else
                cnt--;
        }
        int ans = INF;
        cnt = 0;
        for(i = 2*n; i >= n; i--) {
            ans = min(ans, i-n + t[-cnt]);
            if(i == n)
                break;
            if(a[i-1] == 1)
                cnt++;
            else
                cnt--;
        }
        printf("%d\n", ans);
    }
    return 0;
}