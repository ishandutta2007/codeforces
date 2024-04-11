#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

const int MAXN = 100500;
const int MAXK = 131072;

int calc[MAXN];
int minLeft[2 * MAXK];
int minT[2 * MAXK], maxT[2 * MAXK];
int n, arr[MAXN], curk;
int l, s;

int
getMin(int l, int r)
{
    int res = 1000000001;
    l += curk - 1;
    r += curk - 1;
    while (l < r) {
        res = min(res, min(minT[l], minT[r]));
        l = (l + 1) / 2;
        r = (r - 1) / 2;
    }
    if (l == r) {
        res = min(res, minT[l]);
    }
    return res;
}

int
getMax(int l, int r)
{
    int res = -1000000001;
    l += curk - 1;
    r += curk - 1;
    while (l < r) {
        res = max(res, max(maxT[l], maxT[r]));
        l = (l + 1) / 2;
        r = (r - 1) / 2;
    }
    if (l == r) {
        res = max(res, maxT[l]);
    }
    return res;
}

void
updMin(int x, int val)
{
    x += curk;
    minLeft[x] = min(minLeft[x], val);
    while (x != 1) {
        x /= 2;
        minLeft[x] = min(minLeft[x * 2], minLeft[x * 2 + 1]);
    }
}

int
getMinT(int l, int r)
{
    int res = 1000000000;
    l += curk;
    r += curk;
    while (l < r) {
        res = min(res, min(minLeft[l], minLeft[r]));
        l = (l + 1) / 2;
        r = (r - 1) / 2;
    }
    if (l == r) {
        res = min(res, minLeft[l]);
    }
    return res;
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> s >> l;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    curk = 2;
    while (curk < n) curk *= 2;
    for (int i = curk; i < 2 * curk; ++i) {
        minT[i] = 1000000001;
        maxT[i] = -minT[i];
    }
    for (int i = 1; i <= n; ++i) {
        minT[i + curk - 1] = maxT[i + curk - 1] = arr[i];
    }
    for (int i = curk - 1; i >= 1; --i) {
        minT[i] = min(minT[i * 2], minT[i * 2 + 1]);
        maxT[i] = max(maxT[i * 2], maxT[i * 2 + 1]);
    }
    int lPos = 1;
    for (int i = 1; i <= n; ++i) {
        while (getMax(lPos, i) - getMin(lPos, i) > s) ++lPos;
        calc[i] = lPos;
    }
    curk = 2;
    while (curk <= n) curk *= 2;
    for (int i = 1; i < 2 * curk; ++i) {
        minLeft[i] = 1000000000;
    }
    updMin(0, 0);
    for (int i = 1; i <= n; ++i) {
        int maxLb = i - l + 1, minLb = calc[i];
        if (maxLb >= minLb) {
            int val = getMinT(minLb - 1, maxLb - 1) + 1;
            updMin(i, val);
        }
    }
    int res = getMinT(n, n);
    if (res == 1000000000) {
        res = -1;
    }
    cout << res << '\n';
    return 0;
}