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
typedef pair<ll, ll> pll;
pll p[M];

int main() {
    //freopen("A4.in", "r", stdin);
    scanf("%d", &n);
    ll X1, X2;
    scanf("%I64d%I64d", &X1, &X2);
    for (int i = 0; i < n; i++) {
        ll K, B;
        scanf("%I64d %I64d", &K, &B);
        ll Y1 = X1 * K + B;
        ll Y2 = X2 * K + B;
        p[i] = pll(Y1, Y2);
    }
    sort(p, p + n);
    bool res = 0;
    for (int i = 1; i < n; i++) {
        if (p[i].first > p[i-1].first && p[i].second < p[i-1].second) res = 1;
    }
    puts(res ? "YES" : "NO");
    return 0;
}