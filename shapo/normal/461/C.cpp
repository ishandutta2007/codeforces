#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 100500;
const int MAXK = 131072;

int n, q;
int tree[2 * MAXK];
int val[MAXN];
int leftB, curLen;
int curk;
bool reversed;

void
updVal(int pos, int add)
{
    val[pos] += add;
    pos += curk - 1;
    while (pos != 0) {
        tree[pos] += add;
        pos /= 2;
    }
}

int
getSum(int from, int to)
{
    from += curk - 1;
    to += curk - 1;
    int res = 0;
    while (from < to) {
        if (from % 2 == 1) {
            res += tree[from];
        }
        if (to % 2 == 0) {
            res += tree[to];
        }
        from = (from + 1) / 2;
        to = (to - 1) / 2;
    }
    if (from == to) {
        res += tree[from];
    }
    return res;
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    curk = 2;
    while (curk < n) {
        curk *= 2;
    }
    for (int i = 0; i < n; ++i) {
        tree[curk + i] = 1;
    }
    for (int i = curk - 1; i >= 1; --i) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
    for (int i = 1; i <= n; ++i) {
        val[i] = 1;
    }
    leftB = 1;
    reversed = false;
    curLen = n;
    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int p;
            cin >> p;
            int befP = p, aftP = curLen - p;
            int newLen = max(befP, aftP);
            if (befP < aftP) {
                if (reversed) {
                    leftB -= p;
                    for (int it = 1; it <= befP; ++it) {
                        updVal(leftB - it + 1, val[leftB + it]);
                    }
                } else {
                    leftB += p;
                    for (int it = 1; it <= befP; ++it) {
                        updVal(leftB + it - 1, val[leftB - it]);
                    }
                }
            } else {
                if (reversed) {
                    leftB -= p - 1;
                    for (int it = 1; it <= aftP; ++it) {
                        updVal(leftB + it - 1, val[leftB - it]);
                    }
                } else {
                    leftB += p - 1;
                    for (int it = 1; it <= aftP; ++it) {
                        updVal(leftB - it + 1, val[leftB + it]);
                    }
                }
                reversed = !reversed;
            }
            curLen = newLen;
        } else {
            int l, r;
            cin >> l >> r;
            int res = 0;
            if (reversed) {
                res = getSum(leftB - r + 1, leftB - l);
            } else {
                res = getSum(leftB + l, leftB + r - 1);
            }
            cout << res << '\n';
        }
    }
    return 0;
}