#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MAXN = 100500;
const int ALPH = 26;

int nextV[2 * MAXN][ALPH];
int win[MAXN];
int winLose[MAXN];
int n, k;
int cnt = 1, root;
char s[MAXN];

inline void
clearV(int v)
{
    memset(nextV[root], 0, ALPH * sizeof(nextV[root][0]));
}

void
add(char *s)
{
    for (int cur = root; *s; ++s) {
        int pnt = *s - 'a';
        if (nextV[cur][pnt] == 0) {
            nextV[cur][pnt] = ++cnt;
        }
        cur = nextV[cur][pnt];
    }
}

void
compute(int v)
{
    win[v] = 0;
    win[v] = 0;
    int cntChild = 0;
    for (int i = 0; i < ALPH; ++i) {
        int nv = nextV[v][i];
        if (nv) {
            ++cntChild;
            compute(nv);
            if (!win[nv]) {
                win[v] = 1;
            }
            if (!winLose[nv]) {
                winLose[v] = 1;
            }
        }
    }
    if (cntChild == 0) {
        winLose[v] = 1;
    }
}

int
main()
{
    ios_base::sync_with_stdio(false);
    root = 1;
    clearV(root);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf(" %s", s);
        add(s);
    }
    compute(root);
    if (win[root] == 0) {
        printf("Second\n");
    } else if (winLose[root] == 1 || k % 2 == 1) {
        printf("First\n");
    } else {
        printf("Second\n");
    }
    return 0;
}