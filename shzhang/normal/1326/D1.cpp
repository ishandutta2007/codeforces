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

char s[5005];
//int palinbegin[5005]; /* leftmost begin */
//int palinend[5005]; /* rightmost end */
bool palin[5005][5005];

void work(void)
{
    scanf("%s", s + 1);
    int n = 1;
    while (s[n]) n++;
    n--;
    int l = 0, R = n + 1;
    while (l < n && R > 1 && s[l+1] == s[R-1]) {
        l++, R--;
    }
    for (int si = 1; si <= n; si++) {
        for (int i = 1; i + si - 1 <= n; i++) {
            palin[i][i+si-1] = (s[i] == s[i+si-1] && (si <= 2 || palin[i+1][i+si-2]));
        }
    }
    //printf("\n");
    int anslen = 0, from = 0, to = 0, type = 0;
    if (palin[1][n]) {
        printf("%s", s + 1);
    } else {
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                if (!palin[i][j]) continue;
                if (j + 1 >= R && n - j < min(i, l + 1)) {
                    int nans = n - i + 1 + (n - j);
                    if (nans > anslen) {
                        anslen = nans;
                        from = i, to = j, type = 0;
                    }
                }
                if (i - 1 <= l && n - j > i - 1) {
                    int nans = j + (i - 1);
                    if (nans > anslen) {
                        anslen = nans;
                        from = i, to = j, type = 1;
                    }
                }
            }
        }
        if (type == 0) {
            for (int i = 1; i <= n - to; i++) printf("%c", s[i]);
            for (int i = from; i <= n; i++) printf("%c", s[i]);
        } else {
            for (int i = 1; i <= to; i++) printf("%c", s[i]);
            for (int i = n - (from - 1) + 1; i <= n; i++) printf("%c", s[i]);
        }
    }

    printf("\n");
    //for (int i = 0; i <= n; i++) palinbegin[i] = 6000, palinend[i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) palin[i][j] = false;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    //for (int i = 0; i <= 5000; i++) palinbegin[i] = 6000;
    for (int i = 1; i <= t; i++) work();
    return 0;
}