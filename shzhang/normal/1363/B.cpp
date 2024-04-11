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

int t;

char s[1005];

int main()
{
    scanf("%d", &t);
    for (int d = 1; d <= t; d++) {
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        int left_0 = 0; int left_1 = 0;
        int right_0 = 0; int right_1 = 0;
        for (int i = 1; i <= n; i++) {
            (s[i] == '1' ? right_1 : right_0)++;
        }
        int ans = 1000000000;
        for (int bound = 0; bound <= n; bound++) {
            if (bound) {
                (s[bound] == '1' ? right_1 : right_0)--;
                (s[bound] == '1' ? left_1 : left_0)++;
            }
            ans = min(ans, left_1 + right_0);
            ans = min(ans, right_1 + left_0);
        }
        printf("%d\n", ans);
    }
    return 0;
}