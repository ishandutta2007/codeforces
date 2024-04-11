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

int cnt[200005];

int main()
{
    int t;
    scanf("%d", &t);
    for (int d = 1; d <= t; d++) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) cnt[i] = 0;
        for (int i = 1; i <= n; i++) {
            int x; scanf("%d", &x);
            cnt[((x + i) % n + n) % n]++;
        }
        bool good = true;
        for (int i = 0; i < n; i++) {
            if (cnt[i] > 1) {
                good = false;
            }
        }
        printf("%s\n", good ? "YES" : "NO");
    }
    return 0;
}