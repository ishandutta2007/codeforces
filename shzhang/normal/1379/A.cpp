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

char s[55];
char s2[55];

void work(void)
{
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    const char* goal = "abacaba";
    bool ansfound = false;
    for (int i = 1; i <= n - 6; i++) {
        bool pos_good = true;
        for (int j = 0; j < 7; j++) {
            if (s[i+j] != goal[j] && s[i+j] != '?') pos_good =false;
        }
        if (!pos_good) continue;
        for (int j = 1; j <= n; j++) {
            if (j >= i && j < i + 7) {
                s2[j] = goal[j - i];
            } else if (s[j] == '?') {
                s2[j] = 'x';
            } else {
                s2[j] = s[j];
            }
        }
        int occur = 0;
        for (int j = 1; j <= n - 6; j++) {
            bool occur_good = true;
            for (int k = 0; k < 7; k++) {
                if (s2[j+k] != goal[k]) occur_good = false;
            }
            if (occur_good) occur++;
        }
        if (occur == 1) {
            ansfound = true; break;
        }
    }
    if (!ansfound) {
        printf("NO\n");
    } else {
        printf("YES\n");
        for (int i = 1; i <= n; i++) printf("%c", s2[i]);
        printf("\n");
    }
}

int main()
{
    int T; scanf("%d", &T);
    for (int i = 1; i <= T; i++) work();
    return 0;
}