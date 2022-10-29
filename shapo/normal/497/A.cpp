#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

const int MAXN = 105;

char s[MAXN][MAXN];
int n, m;
int ans;
bool is_less[MAXN], is_eq[MAXN];

int
main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf(" %s", s[i]);
    }
    for (int i = 0; i < n - 1; ++i) {
        is_less[i] = false;
        is_eq[i] = true;
    }
    ans = 0;
    for (int i = 0; i < m; ++i) {
        bool can_do = true;
        for (int j = 0; j < n - 1 && can_do; ++j) {
            if (is_eq[j] && s[j][i] > s[j + 1][i]) {
                can_do = false;
            }
        }
        if (can_do) {
            for (int j = 0; j < n - 1; ++j) {
                if (is_eq[j] && s[j][i] < s[j + 1][i]) {
                    is_eq[j] = false;
                    is_less[j] = true;
                }
            }
        } else {
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}