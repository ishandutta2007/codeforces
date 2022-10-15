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

int a, b;

void work2(set<int>& st, int aserve)
{
    for (int aa = 0; aa <= aserve; aa++) {
        int ba = a - aa;
        int ab = aserve - aa;
        int bb = b - ab;
        if (ba >= 0 && ab >= 0 && bb >= 0) {
            st.insert(ab + ba);
        }
    }
}

void work()
{
    scanf("%d%d", &a, &b);
    set<int> st;
    work2(st, (a + b) / 2);
    work2(st, (a + b + 1) / 2);
    printf("%d\n", (int)st.size());
    while (!st.empty()) {
        printf("%d ", *st.begin());
        st.erase(st.begin());
    }
    printf("\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}