#include <bits/stdc++.h>
using namespace std;

#define M 5001

int a[M], b[M], f[M];
int n, k;

const int mod = 1e9 + 7;

int pw(int x, int y, int z){
	if(!y) return 1;
	int w = pw(x, y/2, z);
	w = 1ll * w * w % z;
    if(y & 1) return 1ll * w * x % z;
    return w;
}
int main() {

    scanf("%d %d", &n, &k);
    for(int i = 1;  i <= n; i ++) scanf("%d", &a[i]);
    if(!k) {
        for(int i = 1; i <= n; i++) printf("%d ", a[i]);
        return 0;
    }
    k --;
    f[0] = 1;
	for(int i = 1; i <= n; i ++) {
        f[i] = 1ll * (1ll * f[i-1] * (k + i) % mod) * pw(i, mod - 2, mod) % mod;
	}
    for(int i = 1; i <= n; i ++) {
        for(int j = i; j <= n; j ++) {
            b[j] = (b[j] + 1ll * f[j-i] * a[i]) % mod;
        }
    }
    for(int i = 1; i <= n; i ++) printf("%d ", b[i]);
    return 0;
}