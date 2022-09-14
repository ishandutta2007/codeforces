#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <random>
#include <ctime>
#include <iomanip>
#include <deque>
#include <queue> 
#include <cmath>
#include <cstring>
#include <cassert>
#include <bitset>
#include <unordered_set>
typedef long long ll;
typedef long double ld;

using namespace std;


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x1, x2;
    scanf("%d%d%d", &n, &x1, &x2);
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        int k1 = (x1 + a[i].first - 1) / a[i].first;
        if (i + k1 < n && a[i + k1].first * (n - i - k1) >= x2) {
            printf("Yes\n");
            printf("%d %d\n", k1, n - i - k1);
            for (int j = i; j < i + k1; j++)
                printf("%d ", a[j].second + 1);
            printf("\n");
            for (int j = i + k1; j < n; j++)
                printf("%d ", a[j].second + 1);
            return 0;
        }
        k1 = (x2 + a[i].first - 1) / a[i].first;
        if (i + k1 < n && a[i + k1].first * (n - i - k1) >= x1) {
            printf("Yes\n");
            printf("%d %d\n", n - i - k1, k1);
            for (int j = i + k1; j < n; j++)
                printf("%d ", a[j].second + 1);
            printf("\n");
            for (int j = i; j < i + k1; j++)
                printf("%d ", a[j].second + 1);
            return 0;
        }
    }
    printf("No");
}