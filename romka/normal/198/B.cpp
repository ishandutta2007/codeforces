#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int n, k, d[100010][2];
bool u[100010][2];
pii q[100010*2];
int qb, qf;
char s1[100010], s2[100010];

bool inq(int i, int j, int dd) {
    if (i < 0) return false;
    if (dd > i) return false;
    if (i >= n) return true;

    if (j == 0 && s1[i] == 'X') return false;
    if (j == 1 && s2[i] == 'X') return false;

    if (u[i][j]) return false;
    u[i][j] = true;

    d[i][j] = dd;
    q[qf++] = pii(i, j);

    return false;
}

int main() {
    scanf("%d %d", &n, &k);
    scanf("%s", s1);
    scanf("%s", s2);
    inq(0, 0, 0);

    bool flag = false;
    while (qb < qf) {
        pii cur = q[qb++];
        int dd = d[cur.first][cur.second];

        flag |= inq(cur.first + 1, cur.second, dd+1);
        flag |= inq(cur.first - 1, cur.second, dd+1);
        flag |= inq(cur.first + k, 1 - cur.second, dd+1);

        if (flag) break;
    }

    if (flag) printf("YES\n"); else printf("NO\n");

    return 0;
}