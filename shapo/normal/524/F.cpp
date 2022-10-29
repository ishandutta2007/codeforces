#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>

using namespace std;

const int MOD[] = {1236823303, 1000000007};
const int BASE[] = {123479, 345791};
const int MAXN = 2005000;
const int MAXK = 4194304;

struct Ans
{
    int left;
    int right;
    int start;
    int len() const
    {
        return left + right;
    }
};

int pows[2][MAXN];
int h[2][MAXN];
int bal[MAXN];
int tree[MAXK];
char s[MAXN];
int n, curk;
int succ[MAXN];

int
get_min(int from, int to)
{
    int res = MAXK;
    from += curk;
    to += curk;
    while (from < to) {
        res = min(res, min(tree[from], tree[to]));
        from = (from + 1) / 2;
        to = (to - 1) / 2;
    }
    if (from == to) {
        res = min(res, tree[from]);
    }
    return res;
}

void
get_ans(int start, Ans &cur)
{
    cur.start = start;
    int min_bal = get_min(start, start + n - 1);
    int start_bal = (start == 0) ? 0 : bal[start - 1];
    cur.left = max(0, start_bal - min_bal);
    int end_bal = bal[start + n - 1] + cur.left - start_bal;
    cur.right = end_bal;
}

inline pair< int, int >
get_hash(int from, int to)
{
    int res[2];
    for (int it = 0; it < 2; ++it) {
        int a = h[it][to], b = (from == 0) ? 0 : 1ll * h[it][from - 1] * pows[it][to - from + 1] % MOD[it];
        res[it] = (a - b);
        if (res[it] < 0) {
            res[it] += MOD[it];
        }
    }
    return {res[0], res[1]};
}

int
check(int p1, int p2, int len)
{
    // printf("check %d %d\n", p1, p2);
    int r = len + 1, l = 0;
    while (l < r - 1) {
        int mid = (l + r) / 2;
        auto h1 = get_hash(p1, p1 + mid - 1), h2 = get_hash(p2, p2 + mid - 1);
        if (h1 == h2) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (l == len) {
        return 0;
    }
    // printf("%d symbols are equal\n", l);
    return (s[p1 + l] < s[p2 + l]) ? -1 : 1;
}

bool
cmp(Ans cur, Ans res)
{
    if (res.start == -1) { // not initialized
        return true;
    }
    if (res.len() > cur.len()) {
        return true;
    }
    if (res.len() < cur.len()) {
        return false;
    }
    int p1 = cur.start, p2 = res.start;
    int rest_len = n;
    if (res.left < cur.left) {
        int rest = cur.left - res.left;
        if (succ[p2] - p2 < rest) {
            return true;
        }
        p2 += rest;
        rest_len -= rest;
    } else if (res.left > cur.left) {
        int rest = res.left - cur.left;
        if (succ[p1] - p1 < rest) {
            return false;
        }
        p1 += rest;
        rest_len -= rest;
    }
    int val = check(p1, p2, rest_len);
    // printf("%d\n", val);
    if (val >= 0) {
        return false;
    } else if (val == -1) {
        return true;
    }
    return false;
}

void
output(const Ans &res)
{
    for (int i = 0; i < res.left; ++i) {
        putchar('(');
    }
    for (int i = 0; i < n; ++i) {
        putchar(s[res.start + i]);
    }
    for (int i = 0; i < res.right; ++i) {
        putchar(')');
    }
    puts("");
}

int
main()
{
    for (int it = 0; it < 2; ++it) {
        pows[it][0] = 1;
        for (int i = 1; i < MAXN; ++i) {
            pows[it][i] = 1ll * BASE[it] * pows[it][i - 1] % MOD[it];
        }
    }
    scanf(" %s", s);
    n = strlen(s);
    for (int i = 0; i < n; ++i) {
        s[i + n] = s[i];
    }
    n *= 2;
    curk = 2;
    while (curk < n) {
        curk *= 2;
    }
    int cur_bal = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            ++cur_bal;
        } else {
            --cur_bal;
        }
        bal[i] = cur_bal;
        tree[curk + i] = cur_bal;
    }
    for (int i = curk - 1; i >= 1; --i) {
        tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
    }
    for (int it = 0; it < 2; ++it) {
        int cur_hash = 0;
        for (int i = 0; i < n; ++i) {
            h[it][i] = cur_hash = (1ll * cur_hash * BASE[it] + s[i]) % MOD[it];
            // printf("%d ", h[it][i]);
        }
        // puts("");
    }
    int last_close = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == ')') {
            last_close = i;
        }
        succ[i] = last_close;
    }
    /* for (int i = 0; i < n; ++i) {
        printf("%d ", succ[i] - i);
    }
    puts("");*/
    Ans res;
    res.start = -1;
    n /= 2;
    for (int i = 0; i < n; ++i) {
        Ans cur;
        get_ans(i, cur);
        if (cmp(cur, res)) {
            res = cur;
        }
        /* output(cur);
        output(res);
        puts("-----------"); */
    }
    output(res);
    return 0;
}