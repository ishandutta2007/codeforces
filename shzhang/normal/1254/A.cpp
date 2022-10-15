#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <set>
#include <queue>

using namespace std;

#define ll long long

bool rice[105][105];
char ans[105][105];

void work(void)
{
    int r, c, k;
    scanf("%d%d%d", &r, &c, &k);
    char s[105];
    int ricecnt = 0;
    for (int i = 1; i <= r; i++) {
        scanf("%s", s + 1);
        for (int j = 1; j <= c; j++) {
            rice[i][j] = (s[j] == 'R');
            if (rice[i][j]) ricecnt++;
        }
    }
    int blkid = 1;
    int curcnt = 0;
    int curchar = 'a';
    for (int i = 1; i <= r; i++) {
        for (int J = 1; J <= c; J++) {
            int j = (i % 2 ? J : c-J+1);
            if (rice[i][j]) {
                if (curcnt >= (blkid <= ricecnt % k ? ricecnt / k + 1 : ricecnt / k)) {
                    curcnt = 0;
                    blkid++;
                    if (curchar == 'z'){
                        curchar = 'A';
                    } else if (curchar == 'Z') {
                        curchar = '0';
                    } else {
                        curchar++;
                    }
                }
                curcnt++;
            }
            ans[i][j] = curchar;
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        work();
    }
    return 0;
}