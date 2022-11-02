#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

const int maxN = 2048;

bitset < maxN > a[maxN];
bitset < maxN > b[maxN], c[maxN];
bitset < maxN > cur;

int n;
char s[maxN][maxN];

int main() {
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        scanf("%d\n", &n);
        for (int i = 0; i < n; i ++)
                gets(s[i]);
        for (int i = 0; i < n; i ++)
                for (int j = 0; j < n; j ++)
                        a[j][i] = s[i][j] - '0';
        for (int i = 0; i < n; i ++) {
                for (int j = 0; j < i; j ++)
                        b[i][j] = 0;
                for (int j = 0; j <= i; j ++)
                        c[i][j] = 1;
                for (int j = i; j < n; j ++)
                        b[i][j] = 1;
                for (int j = i + 1; j < n; j ++)
                        c[i][j] = 0;
        }

        int res = 0;
        for (int i = 0; i + 1 < n; i ++) {
                for (int j = 0; j < n; j ++)
                        cur[j] = a[j][i];
                for (int j = n - 1; j > i; j --)
                        if (cur[j] == 1) {
                                res ++;
                                cur ^= (b[i] & c[j]);
                                a[j] ^= (b[i] & c[j]);
                        }
                for (int j = 0; j < n; j ++)
                        a[j][i] = cur[j];
        }

        for (int i = n - 1; i > 0; i --) {
                for (int j = 0; j < n; j ++)
                        cur[j] = a[j][i];
                for (int j = 0; j < i; j ++) 
                        if (cur[j] == 1) {
                                res ++;
                                cur ^= (b[j] & c[i]);
                                a[j] ^= (b[j] & c[i]);
                        }
                for (int j = 0; j < n; j ++)
                        a[j][i] = cur[j];
        }

        for (int i = 0; i < n; i ++)
                if (a[i][i] != 0) res ++;
        printf("%d\n", res);

        return 0;
}