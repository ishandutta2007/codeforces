//5_E
#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 1000011

int n;
int a[N];
int nxt[N], snxt[N];
int same[N];
bool ok[N];

int main(){
    //freopen("e.in", "r", stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) scanf("%d", &a[i]);

    rotate(a, max_element(a, a + n), a + n);

    nxt[n] = n; snxt[n] = n; same[n] = 0;
    for(int i = n - 1; i >= 0; i --){
        nxt[i] = i + 1;
        while(nxt[i] < n && a[nxt[i]] <= a[i]) nxt[i] = nxt[nxt[i]];

        snxt[i] = i + 1;
        while(snxt[i] < n && a[snxt[i]] < a[i]) snxt[i] = snxt[snxt[i]];
        if(a[i] == a[snxt[i]]) same[i] = same[snxt[i]] + 1;
    }

    long long ans = 0;
    for(int i = 0; i < n; i ++){
        if(nxt[i] == n && a[i] != a[0] && !ok[i]) ans ++;
        if(nxt[i] < n) ans ++;
        ans += same[i];
        int j = i + 1;
        while(j < snxt[i]){
            ans ++;
            if(!i) ok[j] = 1;
            j = snxt[j];
        }
    }

    printf("%I64d\n", ans);
}