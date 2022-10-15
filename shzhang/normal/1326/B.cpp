#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

int n;

ll a[200005];
ll b[200005];
ll x[200005];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", b + i);
    }
    for (int i = 1; i <= n; i++) {
        x[i] = max(a[i-1], x[i-1]);
        a[i] = b[i] + x[i];
        printf("%lld ", a[i]);
    }
    return 0;
}