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

bool lava[5][100005];
int n, q;

int main()
{
    int up_down_cnt = 0;
    int full_block_cnt = 0;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= q; i++) {
        int r, c;
        scanf("%d%d", &r, &c);
        if (lava[r][c] && lava[3-r][c]) full_block_cnt--;
        if (lava[r][c] && lava[3-r][c-1]) up_down_cnt--;
        if (lava[r][c] && lava[3-r][c+1]) up_down_cnt--;
        lava[r][c] = !lava[r][c];
        if (lava[r][c] && lava[3-r][c]) full_block_cnt++;
        if (lava[r][c] && lava[3-r][c-1]) up_down_cnt++;
        if (lava[r][c] && lava[3-r][c+1]) up_down_cnt++;
        printf("%s\n", up_down_cnt || full_block_cnt ? "No" : "Yes");
    }
    return 0;
}