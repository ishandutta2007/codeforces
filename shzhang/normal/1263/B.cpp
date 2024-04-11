#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

#define ll long long

bool cmp(char* a, char* b)
{
    for (int i = 0; i < 4; i++) {
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
    }
    return false;
}

void work(void)
{
    int n;
    scanf("%d", &n);
    char* strs[15];
    for (int i = 1; i <= n; i++) {
        char* s = new char[5];
        scanf("%s", s);
        strs[i-1] = s;
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        bool found_same = false;
        for (int j = 0; j < i; j++) {
            if (!strcmp(strs[i], strs[j])) {
                found_same = true; break;
            }
        }
        if (!found_same) continue;
        ans++;
        for (int k = 0; k <= 9; k++) {
            char old = strs[i][0];
            strs[i][0] = k + '0';
            bool good = true;
            for (int l = 0; l < n; l++) {
                if (i != l && !strcmp(strs[i], strs[l])) {
                    good = false; break;
                }
            }
            if (good) {
                goto loop_end;
            } else {
                strs[i][0] = old;
            }
        }
        loop_end:
            ;
    }
    printf("%d\n", ans);
    for (int i = 0; i < n; i++) printf("%s\n", strs[i]);
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        work();
    }
    return 0;
}