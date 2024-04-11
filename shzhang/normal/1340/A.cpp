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

int t;
int n;

int p[100005];
int pos[100005];

void work(void)
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", p + i);
        pos[p[i]] = i;
    }
    int last = n;
    int minpos = pos[1];
    for (int i = 2; i <= n; i++) {
        if (pos[i] != pos[i-1] + 1) {
            if (pos[i-1] != last) {
                printf("No\n"); return;
            }
            last = minpos - 1;
        }
        minpos = min(minpos, pos[i]);
    }
    printf("Yes\n");
}

int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        work();
    }
    return 0;
}