#include <cstdio>
#include <iostream>
using namespace std;
const int N = 2e5 + 1, p = 998244353;

int n, k, _f[N], _g[N], *f = _f, *g = _g, ans[N];

int main(){
    scanf("%d%d", &n, &k);
    g[0] = 1;
    for (int i = k, sum = 0; sum <= n; sum += ++i){
        swap(f, g);
        for (int j = 0; j <= n; j++){
            if(j >= i)
                g[j] = (g[j - i] + f[j - i]) % p;
            else
                g[j] = 0;
            ans[j] = (ans[j] + g[j]) % p;
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    return 0;
}