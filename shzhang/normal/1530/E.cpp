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

int n;
char s[100005];
int freq[26];

void output_rest()
{
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < freq[i]; j++) {
            printf("%c", 'a' + i);
        }
    }
}

void work()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        freq[s[i] - 'a']++;
    }
    int types = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i]) types++;
    }
    if (types == 1) {
        printf("%s", s + 1); return;
    }
    int lowchar = 1000;
    for (int i = 0; i < 26; i++) {
        if (freq[i]) lowchar = min(lowchar, i);
        if (freq[i] == 1) {
            printf("%c", i + 'a');
            freq[i]--;
            output_rest(); return;
        }
    }
    printf("%c", lowchar + 'a'); freq[lowchar]--;
    if (freq[lowchar] > 1 + (n - 2) / 2) {
        int secchar = lowchar + 1;
        while (!freq[secchar]) secchar++;
        printf("%c", secchar + 'a'); freq[secchar]--;
        if (types == 2) {
            while (freq[secchar]) {
                printf("%c", secchar + 'a'); freq[secchar]--;
            }
            while (freq[lowchar]) {
                printf("%c", lowchar + 'a'); freq[lowchar]--;
            }
        } else {
            int pre = secchar;
            for (int i = 1; i <= n - 2; i++) {
                for (int j = 0; j < 26; j++) {
                    if (freq[j] && (pre != lowchar || j != secchar)) {
                        printf("%c", j + 'a');
                        freq[j]--;
                        pre = j;
                        break;
                    }
                }
            }
        }
    } else {
        printf("%c", lowchar + 'a'); freq[lowchar]--;
        int pre = lowchar;
        for (int i = 1; i <= n - 2; i++) {
            for (int j = 0; j < 26; j++) {
                if (freq[j] && (pre != lowchar || j != lowchar)) {
                    printf("%c", j + 'a');
                    freq[j]--;
                    pre = j;
                    break;
                }
            }
        }
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int d = 1; d <= t; d++) {
        work(); printf("\n");
        for (int i = 0; i < 26; i++) freq[i] = 0;
    }
    return 0;
}