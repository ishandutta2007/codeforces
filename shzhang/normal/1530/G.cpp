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

int n, k;
char A[2005], B[2005];
char tmp[2005];

int ones_cnt; int ones_cnt_b;

void flip_raw(int l, int r, char* s)
{
    while (l < r) {
        swap(s[l], s[r]);
        l++; r--;
    }
}

void flip_func(int l, int r, char* s, vector<pair<int, int> >& ops)
{
    ops.push_back(make_pair(l, r));
    flip_raw(l, r, s);
}

#define flip(l, r) flip_func(l, r, s, ops)

void to_standard(char* s, vector<pair<int, int> >& ops)
{
    for (int i = 1; i < ones_cnt - k; i++) {
        int cur = i - 1; int cnt = 0;
        while (cnt < k) {
            cur++; if (s[cur] == '1') cnt++;
        }
        flip(i, cur);
    }
    int from = ones_cnt - k;
    int to = n;
    while (true) {
        while (s[from] == '0') from++;
        while (s[to] == '0') to--;
        if (to - from + 1 <= k + 1) break;
        int lcnt = 0, rcnt = 0;
        while (s[from + lcnt] == '1') lcnt++;
        while (s[to - rcnt] == '1') rcnt++;
        if (lcnt <= rcnt) {
            flip(from + 1, to);
        } else {
            flip(from, to - 1);
        }
    }
    if (k % 2 == 0) {
        flip(ones_cnt - k, to - 1);
        return;
    }
    from = ones_cnt - k;
    for (int i = 1; i <= (k + 1) / 2; i++) {
        flip(from, to - 1);
        flip(from + 1, to);
    }
}

void work()
{
    scanf("%d%d", &n, &k);
    scanf("%s%s", A + 1, B + 1);
    ones_cnt = ones_cnt_b = 0;
    bool equal = true;
    for (int i = 1; i <= n; i++) {
        if (A[i] != B[i]) equal = false;
        if (A[i] == '1') ones_cnt++;
        if (B[i] == '1') ones_cnt_b++;
    }
    if (equal) {
        printf("0\n"); return;
    }
    if (k == 0 || k > ones_cnt || ones_cnt != ones_cnt_b) {
        printf("-1\n"); return;
    }
    if (k == ones_cnt) {
        int a_from = 1, a_to = n;
        int b_from = 1, b_to = n;
        while (A[a_from] == '0') a_from++;
        while (B[b_from] == '0') b_from++;
        while (A[a_to] == '0') a_to--;
        while (B[b_to] == '0') b_to--;
        if (a_to - a_from != b_to - b_from) {
            printf("-1\n"); return;
        }
        flip_raw(min(a_from, b_from), max(a_to, b_to), A);
        equal = true;
        for (int i = 1; i <= n; i++) {
            if (A[i] != B[i]) equal = false;
        }
        if (equal) {
            printf("1\n%d %d\n", min(a_from, b_from), max(a_to, b_to)); return;
        }
        flip_raw(b_from, b_to, A);
        equal = true;
        for (int i = 1; i <= n; i++) {
            if (A[i] != B[i]) equal = false;
        }
        if (equal) {
            printf("2\n%d %d\n%d %d\n", min(a_from, b_from), max(a_to, b_to), b_from, b_to); return;
        }
        printf("-1\n");
        return;
    }
    vector<pair<int, int> > op1, op2;
    to_standard(A, op1);
    to_standard(B, op2);
    equal = true;
    for (int i = 1; i <= n; i++) {
        if (A[i] != B[i]) equal = false;
    }
    if (!equal) {
        printf("-1\n"); return;
    }
    printf("%d\n", (int)(op1.size() + op2.size()));
    for (int i = 0; i < op1.size(); i++) {
        printf("%d %d\n", op1[i].first, op1[i].second);
    }
    reverse(op2.begin(), op2.end());
    for (int i = 0; i < op2.size(); i++) {
        printf("%d %d\n", op2[i].first, op2[i].second);
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}