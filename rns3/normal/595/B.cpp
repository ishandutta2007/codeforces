#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
#define M 202020
const int mod = 1000000007;
typedef pair<int, int> pii;
#define x first
#define y second

int n;
int k;
int A[M], B[M];


int main() {
   // freopen("A2.in", "r", stdin);
    scanf("%d", &n);
    scanf("%d", &k);
    n /= k;
    int ans = 1;
    int p = 1;
    for (int i = 0; i < k; i++) p = p * 10;
    for (int i = 0; i < n; i++) scanf("%d", A + i);
    for (int i = 0; i < n; i++) scanf("%d", B + i);
    for (int i = 0; i < n; i++) {
        int a = A[i], b = B[i];
        int u, v, w;
        u = (p / 10 * b - 1 + a) / a;
        v = (p / 10 * (b+1) - 1 + a) / a;
        w = (p - 1 + a) / a;
        w -= v - u;
        ans = 1ll * ans * w % mod;
    }
    printf("%d\n", ans);
    return 0;
}