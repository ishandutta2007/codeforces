#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <utility>

using namespace std;

#define ll long long

ll a[1050005];
int leaf[1050005];
int depth[1050005];
int n;

int h, g;

int f[1050005];

void update(int node)
{
    if (node * 2 >= (1 << h) || (!a[node * 2 + 1] && !a[node * 2])) {
        leaf[node] = node;
        f[node] = depth[node] > g ? node : 0;
    } else {
        if (a[node * 2 + 1] > a[node * 2]) {
            leaf[node] = leaf[node * 2 + 1];
        } else {
            leaf[node] = leaf[node * 2];
        }
        if (depth[leaf[node]] > g) {
            f[node] = node;
        } else {
            if (a[f[node * 2]] > a[f[node * 2 + 1]]) {
                f[node] = f[node * 2];
            } else {
                f[node] = f[node * 2 + 1];
            }
        }
    }
}

void F(int node)
{
    //fprintf(stderr, "f %d\n", node);
    if (node * 2 >= (1 << h)) {
        a[node] = 0;
    } else {
        if (a[node * 2 + 1] > a[node * 2]) {
            a[node] = a[node * 2 + 1];
            F(node * 2 + 1);
        } else {
            a[node] = a[node * 2];
            F(node * 2);
        }
        //val2node[a[node]] = node;
        update(node);
    }
}

void work(void)
{
    //st.clear();
    scanf("%d%d", &h, &g);
    ll ans = 0;
    for (int i = 1; i < (1 << h); i++) {
        int va;
        scanf("%d", &va); a[i] = va; ans += a[i];
    }
    for (int i = (1 << h) - 1; i >= 1; i--) {
        update(i);
    }
    vector<int> ops;
    //int curval = (1 << h) - 1;
    for (int i = 1; i <= (1 << h) - (1 << g); i++) {
        int node = f[1];
        ops.push_back(node);
        ans -= a[node];
        F(node);
        for (; node >= 1; node /= 2) {
            update(node);
        }
    }
    printf("%lld\n", ans);
    for (int i = 0; i < ops.size(); i++) {
        printf("%d ", ops[i]);
    }
    printf("\n");
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int d = 1; d <= 22; d++) {
        for (int i = (1 << (d - 1)); i < min(1050000, (1 << d)); i++) {
            depth[i] = d;
        }
    }
    for (int i = 1; i <= t; i++) {
        work();
    }
    return 0;
}