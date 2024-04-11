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

const int N = 100;
char a[N][N];
int x[4];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    int ans = n * n * 4;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < n; j++) {
            scanf("%s", &a[j]);
            for (int k = 0; k < n; k++)
                if ((j + k) % 2 == a[j][k] - '0')
                    x[i]++;
        }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < i; j++) {
            int cs = x[i] + x[j];
            for (int k = 0; k < 4; k++)
                if (i != k && j != k)
                    cs += n * n - x[k];
            ans = min(ans, cs);
        }
    }
    printf("%d", ans);
}