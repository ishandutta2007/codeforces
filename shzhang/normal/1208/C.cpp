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

int grid[4][4];
//int ans[1005][1005];

int main()
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            grid[i][j] = i * 4 + j;
        }
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", grid[i%4][j%4] + (j/4)*16 + (i/4)*(n/4)*16);
        }
        printf("\n");
    }
    return 0;
}