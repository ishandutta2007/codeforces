#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define M 1000000007
#define maxn 200019
using namespace std;

int f[maxn];
int main(){
    int n, m;
    f[1] = 2, f[2] = 4;
    srep(i, 3, maxn) f[i] = (f[i - 1] + f[i - 2]) % M;
    scanf("%d %d", &n, &m);
    printf("%lld", ((ll)f[n] + f[m] - 2 + M) % M);
    return 0;
}