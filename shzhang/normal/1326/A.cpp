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

int main()
{
    int t;
    scanf("%d", &t);
    for (int d = 1; d <= t; d++) {
        int n;
        scanf("%d", &n);
        if (n == 1) {
            printf("-1\n");
        } else {
            printf("2");
            for (int i = 1; i < n; i++) {
                printf("3");
            }
            printf("\n");
        }
    }
    return 0;
}