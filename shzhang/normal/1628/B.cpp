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

bool use2[26][26];
bool use3[26][26][26];
bool use3p[26][26];
int seqlen[100005];
int seq[100005][5];

int n;

void work()
{
    scanf("%d", &n);
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            use2[i][j] = use3p[i][j] = false;
            for (int k = 0; k < 26; k++) {
                use3[i][j][k] = false;
            }
        }
    }
    char tmp[10];
    for (int i = 1; i <= n; i++) {
        scanf("%s", tmp + 1);
        seqlen[i] = strlen(tmp + 1);
        for (int j = 1; j <= seqlen[i]; j++)
            seq[i][j] = tmp[j] - 'a';
    }
    for (int i = 1; i <= n; i++) {
        if (seqlen[i] == 1 ||
            (seqlen[i] == 2 && seq[i][1] == seq[i][2]) ||
            (seqlen[i] == 3 && seq[i][1] == seq[i][3])) {
            printf("YES\n"); return;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (seqlen[i] == 2) {
            if (use2[seq[i][2]][seq[i][1]] ||
                use3p[seq[i][2]][seq[i][1]]) {
                printf("YES\n"); return;
            }
            use2[seq[i][1]][seq[i][2]] = true;
        } else {
            if (use3[seq[i][3]][seq[i][2]][seq[i][1]] ||
                use2[seq[i][3]][seq[i][2]]) {
                printf("YES\n"); return;
            }
            use3[seq[i][1]][seq[i][2]][seq[i][3]] = true;
            use3p[seq[i][1]][seq[i][2]] = true;
        }
    }
    printf("NO\n"); return;
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}