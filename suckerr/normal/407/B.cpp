#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1111;
const int MOD = 1000000007;

int n, a[N];
int f[N];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    f[1] = 1;
    for(int i = 2; i <= n; i++) {
        f[i] = 1;
        for(int j = a[i]; j < i; j++) {
            f[i] += f[j];
            f[i]++;
            f[i] %= MOD;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += f[i] + 1;
        ans %= MOD;
    }
    
    printf("%d\n", ans);    
    return 0;
}