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
#define updiv(a, b) ((a) % b ? (a) / b + 1 : (a) / b)

char s[100005];

void work(void)
{
    int n, k; scanf("%d%d", &n, &k);
    scanf("%s", s + 1);
    sort(s + 1, s + n + 1);
    if (s[1] == s[n]) {
        for (int i = 1; i <= updiv(n, k); i++) {
            printf("%c", s[1]);
        }
        printf("\n"); return;
    }

    if (s[1] != s[k]) {
        printf("%c\n", s[k]);
    } else {
        if (k < n && s[k+1] == s[n]) {
            printf("%c", s[k]);
            //printf("%d", updiv(n-k, k));
            for (int i = k + 1; i <= k + updiv(n - k, k); i++) {
                printf("%c", s[i]);
            }
            printf("\n");
        } else {
            printf("%s\n", s + k);
        }
    }
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