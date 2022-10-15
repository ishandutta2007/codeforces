#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <utility>

using namespace std;

int n, m;
int A[55][55];
int B[55][55];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &(A[i][j]));
        }
    }
    vector<pair<int, int> > ops;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (A[i][j] && A[i][j+1] && A[i+1][j] && A[i+1][j+1]) {
                ops.push_back(make_pair(i, j));
                B[i][j] = B[i][j+1] = B[i+1][j] = B[i+1][j+1] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i][j] != B[i][j]) {
                printf("-1"); return 0;
            }
        }
    }
    printf("%d\n", (int)ops.size());
    for (int i = 0; i < ops.size(); i++) {
        printf("%d %d\n", ops[i].first, ops[i].second);
    }
    return 0;
}