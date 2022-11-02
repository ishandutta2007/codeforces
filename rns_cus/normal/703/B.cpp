#include <bits/stdc++.h>
using namespace std;

#define N 1000000

int n, k, id[N], c[N];
__int64 ans, tmp;

int main()
{
    //freopen("1.in", "r", stdin);
    scanf("%d%d", &n, &k);
    tmp = 0;
    for(int i = 1; i <= n; i ++) scanf("%d", c+i), tmp += c[i];
    for(int i = 0; i < k; i ++) scanf("%d", id+i);
    int m = 0, fg = 0;
    ans = 0;
    for(int i = 1; i <= n; i ++){
        if(i == id[m] && m < k){
            if(i != 1){
                 tmp -= c[i];
                 //if(id[m] == n) {ans += c[1]*c[n]; continue;}
                 if(i-1 == id[m-1])  ans += c[i] * tmp;
                 else  ans += c[i] * (tmp - c[(i-1)%n]);
                 if(id[m] == n && fg) ans += c[1]*c[n];
                 m ++;
            }
            else fg = 1, tmp -= c[i], ans += c[i] * (tmp - c[n]), m ++;
        }
        else{
            if(i != n-1) ans += c[i] * c[(i+1)%n];
            else ans += c[i] * c[n];
        }
    }
    printf("%I64d\n",ans);
}