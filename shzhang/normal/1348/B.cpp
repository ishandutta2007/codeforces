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

using namespace std;

#define ll long long

int t;

void work(void)
{
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> vals; vector<int> vals2;
    for (int i = 1; i <= n; i++) {
        int a; scanf("%d", &a); vals.push_back(a);
        vals2.push_back(a);
    }
    sort(vals2.begin(), vals2.end());
    int dist = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || vals2[i] != vals2[i-1]) dist++;
    }
    if (dist > k) {
        printf("-1\n"); return;
    }
    printf("%d\n", k * n);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < vals2.size(); j++) {
            if (j == 0 || vals2[j] != vals2[j-1]) printf("%d ", vals2[j]);
        }
        for (int j = 1; j <= k - dist; j++) {
            printf("%d ", vals2[0]);
        }
    }
    printf("\n");
}

int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        work();
    }
    return 0;
}