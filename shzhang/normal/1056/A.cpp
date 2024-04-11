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
#include <random>
#include <chrono>

using namespace std;

#define ll long long

int cnt[105];
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        for (int j  =1; j <= x; j++) {
            int val; scanf("%d", &val);
            cnt[val]++;
        }
    }
    for (int i = 1; i <= 100; i++) {
        if (cnt[i] == n) {
            printf("%d ", i);
        }
    }
    return 0;
}