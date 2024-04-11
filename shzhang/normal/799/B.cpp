#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;

vector<int> prices[4][4]; int n, m;

int p[200005];
int a[200005];
int b[200005];

bool cmp(int A, int B)
{
    return A > B;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", p + i);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", b + i);
    }
    for (int i = 1; i <= n; i++) {
        prices[a[i]][b[i]].push_back(p[i]);
    }
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            sort(prices[i][j].begin(), prices[i][j].end(), cmp);
        }
    }
    scanf("%d", &m);
    for (int buyer = 1; buyer <= m; buyer++) {
        int c;
        scanf("%d", &c);
        int bestprice = 2000000000;
        int besti = 0, bestj = 0;
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                if (i != c && j != c) continue;
                if (!prices[i][j].empty() && prices[i][j].back() < bestprice) {
                    bestprice = prices[i][j].back(); besti = i, bestj = j;
                }
            }
        }
        if (!besti) {
            printf("-1 ");
        } else {
            printf("%d ", bestprice);
            prices[besti][bestj].pop_back();
        }
    }
    return 0;
}