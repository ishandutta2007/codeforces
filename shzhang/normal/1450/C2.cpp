#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

char grid[305][305];
char s[305];

void work()
{
    int n; scanf("%d", &n);
    int cnt[3], x[3], o[3];
    cnt[0] = cnt[1] = cnt[2] = 0;
    x[0] = x[1] = x[2] = 0;
    o[0] = o[1] = o[2] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        for (int j = 1; j <= n; j++) {
            grid[i][j] = s[j];
            if (grid[i][j] != '.') {
                cnt[(i+j)%3]++;
                if (grid[i][j] == 'X') {
                    x[(i+j)%3]++;
                } else {
                    o[(i+j)%3]++;
                }
            }
        }
    }
    int bestv = 0; int amt = cnt[0] + cnt[1];
    for (int i = 0; i < 3; i++) {
        if (cnt[i] + cnt[(i+1)%3] < amt) {
            bestv = i; amt = cnt[i] + cnt[(i+1)%3];
        }
    }
    bool fill_x = false;
    if (x[bestv] + o[(bestv+1)%3] > o[bestv] + x[(bestv+1)%3]) fill_x = true;
    //printf("%d %d\n", bestv, (int)fill_x);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i + j) % 3 == (bestv + 5) % 3) continue;
            if (grid[i][j] == '.') continue;
            char goalc;
            if ((i + j) % 3 == bestv) {
                goalc = fill_x ? 'X' : 'O';
            } else {
                goalc = fill_x ? 'O' : 'X';
            }
            grid[i][j] = goalc;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}