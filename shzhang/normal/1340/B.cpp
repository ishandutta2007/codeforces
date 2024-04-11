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

int bwt[1000];

int n, k;
int val[2005];
bool suffix[2005][2005];

int ans[2005];

int nums[] = {119, 18, 93, 91, 58, 107, 111, 82, 127, 123};

int main()
{
    for (int i = 0; i <= 500; i++) {
        for (int j = 0; j <= 8; j++) {
            if (i & (1 << j)) bwt[i]++;
        }
    }
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        char s[7];
        scanf("%s", s);
        for (int j = 0; j < 7; j++) {
            if (s[j] == '1') val[i] |= (1 << (6 - j));
        }
    }
    //for (int i = 1; i <= k; i++) ranking[0][i] = 0;
    //ranking[0][0] = 1;
    suffix[n+1][0] = true;
    for (int i = n; i >= 1; i--) {
        for (int v = 0; v <= 9; v++) {
            if ((nums[v] & val[i]) != val[i]) continue;
            int req_cnt = bwt[nums[v] ^ val[i]];
            for (int j = req_cnt; j <= k; j++) {
                suffix[i][j] = (suffix[i][j] || suffix[i+1][j-req_cnt]);
            }
        }
    }
    if (!suffix[1][k]) {
        printf("-1"); return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 9; j >= 0; j--) {
            if ((nums[j] & val[i]) != val[i]) continue;
            int req_cnt = bwt[nums[j] ^ val[i]];
            if (!suffix[i+1][k - req_cnt]) continue;
            ans[i] = j; k -= req_cnt; break;
        }
    }
    for (int i = 1; i <= n; i++) printf("%d", ans[i]);
    return 0;
}