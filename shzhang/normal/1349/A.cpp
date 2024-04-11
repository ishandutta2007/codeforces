#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <utility>

using namespace std;

#define ll long long

vector<int> factor[200005];

int n;
int a[100005];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        int cur = a[i];
        for (int v = 2; v * v <= a[i]; v++) {
            if (cur % v == 0) {
                //printf("%d ", v);
                int pwr = 0;
                while (cur % v == 0) {
                    cur /= v; pwr++;
                }
                factor[v].push_back(pwr);
            }
        }
        if (cur > 1) factor[cur].push_back(1);
        //printf("\n");
    }
    ll ans = 1;
    for (int i = 1; i <= 200000; i++) {
        int finpwr = 0;
        if (factor[i].size() >= n - 1) {
            sort(factor[i].begin(), factor[i].end());
            if (factor[i].size() == n - 1) {
                finpwr = factor[i][0];
            } else {
                finpwr = factor[i][1];
            }
        }
        ll cur = 1;
        for (int x = 1; x <= finpwr; x++) {
            cur *= (ll)i;
        }
        ans *= cur;
    }
    printf("%lld", ans);
    return 0;
}