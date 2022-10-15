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
char s[200005];
char s2[200005];
int psum[200005];

bool isgood(char* seq)
{
    int curcnt = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (seq[i] == '(') {
            curcnt++;
        } else {
            curcnt--;
        }
        if (curcnt < 0) return false;
    }
    return true;
}

void work()
{
    scanf("%d", &n);
    scanf("%s", s + 1);
    if (isgood(s)) {
        printf("0\n"); return;
    }
    for (int i = 1; i <= 2 * n; i++) {
        s2[i] = s[i];
        psum[i] = psum[i-1] + (s[i] == '(' ? 1 : -1);
    }
    int lpos = 0, lval = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (psum[i] < 0) break;
        if (psum[i] >= lval) {
            lval = psum[i];
            lpos = i;
        }
    }
    int rpos = 0, rval = 0;
    for (int i = 2 * n; i >= 1; i--) {
        if (psum[i] < 0) break;
        if (psum[i] >= rval) {
            rval = psum[i];
            rpos = i;
        }
    }
    // flip from lpos + 1 to rpos
    int curl = lpos + 1, curr = rpos;
    while (curl < curr) {
        swap(s2[curl], s2[curr]);
        curl++; curr--;
    }
    if (isgood(s2)) {
        printf("1\n%d %d\n", lpos + 1, rpos);
        return;
    }
    int gpos = 0, gval = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (psum[i] >= gval) {
            gval = psum[i];
            gpos = i;
        }
    }
    printf("2\n%d %d\n%d %d\n", 1, gpos, gpos+1, 2 * n);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}