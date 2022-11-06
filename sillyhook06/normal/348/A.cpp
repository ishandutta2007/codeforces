#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define rep(i,n) for (int i=1;i<=n;++i)
int n, m, x;
long long sum;
int main()
{
    scanf("%d", &n);
    rep(i, n) scanf("%d", &x), m = max(m, x), sum += x;
    if (sum > 1LL * m * (n - 1)) printf("%I64d\n", (sum-1) / (n-1) + 1);
    else printf("%d\n", m);
    return 0;
}