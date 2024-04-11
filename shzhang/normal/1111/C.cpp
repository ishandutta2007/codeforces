#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <cstdlib>

#define ll long long

using namespace std;

int n, k, A, B;
int a[100005];

ll cost(int from, int to)
{
    int* pos1 = lower_bound(a + 1, a + k + 1, from);
    int* pos2 = upper_bound(a + 1, a + k + 1, to);
    if (pos1 >= pos2) {
        return A;
    }
    if (from == to) return (pos2 - pos1) * (ll)(B);
    return min((ll)(to - from + 1) * (ll)(pos2 - pos1) * (ll)(B),
        cost(from, (from + to) / 2) + cost((from + to) / 2 + 1, to));
}

int main()
{
    scanf("%d%d%d%d", &n, &k, &A, &B);
    for (int i = 1; i <= k; i++) {
        scanf("%d", a + i);
    }
    sort(a + 1, a + k + 1);
    printf("%lld", cost(1, 1 << n));
    return 0;
}