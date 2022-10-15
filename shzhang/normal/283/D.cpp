#include <cstdio>
#include <vector>

using namespace std;

#define ll long long

ll a[5005];
int pwr2[5005];
vector<int> nxt[5005];
int f[5005];
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a + i);
        while (!(a[i] & 1LL)) {
            a[i] >>= 1LL; pwr2[i]++;
        }
        //printf("%lld ", a[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] % a[j] != 0LL) continue;
            //printf("1 %d %d\n", i, j);
            if (pwr2[i] < pwr2[j] && pwr2[j] - pwr2[i] != j - i && pwr2[j] > j-i-1) continue;
            //printf("2 %d %d\n", i, j);
            if (pwr2[i] >= pwr2[j] && pwr2[j] > j-i-1) continue;
            //printf("3 %d %d\n", i, j);
            nxt[i].push_back(j);
            //printf("%d %d\n", i, j);
        }
        nxt[i].push_back(n + 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < nxt[i].size(); j++) {
            f[nxt[i][j]] = max(f[nxt[i][j]], f[i] + 1);
        }
    }
    printf("%d", n - f[n+1]);
    return 0;
}