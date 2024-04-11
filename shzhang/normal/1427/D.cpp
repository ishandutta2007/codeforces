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
int a[60];
int tmp[60];
vector<vector<int> > grplist;

void do_op(vector<int> grp)
{
    int cur = n;
    int acur = 0;
    int rgrpcnt = 0;
    for (int i = 0; i < grp.size(); i++) {
        int x = grp[i];
        if (x) rgrpcnt++;
        cur -= x;
        for (int j = 1; j <= x; j++) {
            tmp[cur + j] = a[acur + j];
        }
        acur += x;
    }
    for (int i = 1; i <= n; i++) a[i] = tmp[i];
    if (rgrpcnt >= 2) grplist.push_back(grp);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) {
        int pos1 = 0, posi = 0, posi1 = 0;;
        for (int j = 1; j <= n; j++) {
            if (a[j] == 1) pos1 = j;
            if (a[j] == i) posi = j;
            if (a[j] == i + 1) posi1 = j;
        }
        if (pos1 <= posi) {
            if (i == n) {
                goto done;
            }
            vector<int> ops;
            if (posi1 < pos1) {
                //printf("A");
                ops.push_back(posi1 - 1);
                ops.push_back(pos1 - posi1);
                ops.push_back(posi - pos1 + 1);
                ops.push_back(n - posi);
            } else {
                //printf("B");
                ops.push_back(pos1 - 1);
                for (int X = pos1; X <= posi; X++) ops.push_back(1);
                ops.push_back(posi1 - posi);
                ops.push_back(n - posi1);
            }
            do_op(ops);
        } else {
            vector<int> ops;
            if (i == n) {
                for (int X = 1; X <= n; X++) ops.push_back(1);
            } else if (posi1 < pos1) {
                //printf("C");
                ops.push_back(posi1 - 1);
                ops.push_back(posi - posi1);
                for (int X = posi; X <= pos1; X++) ops.push_back(1);
                ops.push_back(n - pos1);
            } else {
                //printf("D");
                ops.push_back(posi - 1);
                ops.push_back(pos1 - posi + 1);
                ops.push_back(posi1 - pos1);
                ops.push_back(n - posi1);
            }
            do_op(ops);
        }
    }
    done:
    //for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    printf("%d\n", (int)grplist.size());
    for (int i = 0; i < grplist.size(); i++) {
        vector<int> grp = grplist[i];
        int rsiz = 0;
        for (int j = 0; j < grp.size(); j++) {
            if (grp[j]) rsiz++;
        }
        printf("%d ", rsiz);
        for (int j = 0; j < grp.size(); j++) {
            if (grp[j]) printf("%d ", grp[j]);
        }
        printf("\n");
    }
    return 0;
}