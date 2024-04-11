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
#include <map>
#include <random>
#include <chrono>

using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

#define HASHES 40
#define lowbit(x) ((x)&(-(x)))

int n, q;

map<int, int*> table;

int ftree[HASHES][300005];
int a[300005];

int rquery(int* arr, int v)
{
    int ans = 0;
    while (v) {
        ans += arr[v]; v -= lowbit(v);
    }
    return ans;
}

void modify(int* arr, int loc, int val)
{
    //printf("!!%d %lld\n", loc, val);
    while (loc <= n) {
        arr[loc] += val; loc += lowbit(loc);
    }
    //printf("! %p %d %p\n", valarr, loc, valarr + loc);
}

void modifyelem(int pos, int val)
{
    //printf("! %d %d\n", pos, val);
    if (!(table.count(val))) {
        int* ptr = new int[HASHES];
        for (int i = 0; i < HASHES; i++) {
            ptr[i] = rng() % 5000;
        }
        table[val] = ptr;
    }
    int* ptr1 = table[val];
    int* ptr2 = table[a[pos]];
    for (int i = 0; i < HASHES; i++) {
        modify(ftree[i], pos, ptr1[i] - (a[pos] ? ptr2[i] : 0));
        //printf("!!!%d %d %lld %p %p\n", i, pos, fval[i][pos], fval[i], fval[i] + pos);
    }
    a[pos] = val;
}

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        int A; scanf("%d", &A);
        modifyelem(i, A);
    }

    /*for (int j = 0; j < 2; j++) {
        for (int i = 1; i <= n; i++) {
            printf("%lld ", fval[j][i]);
        }
    }*/
    for (int qr = 1; qr <= q; qr++) {
        int typ; scanf("%d", &typ);
        if (typ == 1) {
            int pos; int x; scanf("%d%d", &pos, &x);
            modifyelem(pos, x);
        } else {
            int l, r, k; scanf("%d%d%d", &l, &r, &k);
            bool ans = true;
            for (int i = 0; i < HASHES; i++) {
                int sum = rquery(ftree[i], r) - rquery(ftree[i], l-1);
                if (sum % k) {
                    ans = false; break;
                }
            }
            printf("%s\n", ans ? "YES" : "NO");
        }
    }
    return 0;
}