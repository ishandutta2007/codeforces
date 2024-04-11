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
#include <cmath>

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
int x[2005], y[2005], a[2005];


int uf[500005];

int fin(int A)
{
    if (uf[A] == A) return A;
    return uf[A] = fin(uf[A]);
}

void un(int A, int b)
{
    A = fin(A); b = fin(b);
    if (A == b) return;
    uf[A] = b;
}

// https://codeforces.com/blog/entry/72815
bool up(int p)
{
    return y[p] > 0 or (y[p] == 0 and x[p] >= 0);
}

ll cross(int n1, int n2)
{
    return (ll)x[n1] * (ll)y[n2] - (ll)y[n1] * (ll)x[n2];
}

bool cmp(int n1, int n2)
{
    return up(n1) == up(n2) ? cross(n1, n2) > 0 : up(n1) < up(n2);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) uf[i] = i;
    int root = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", x + i, y + i, a + i);
        un(i, a[i]);
        if (a[i] != i) root = i;
    }
    if (root == 0) {
        printf("0"); return 0;
    }
    int rx = x[root], ry = y[root];
    for (int i = 1; i <= n; i++) {
        x[i] -= rx; y[i] -= ry;
    }
    vector<int> seq;
    for (int i = 1; i <= n; i++) {
        if (i != root) {
            seq.push_back(i);
        }
    }
    vector<pair<int, int> > ops;
    sort(seq.begin(), seq.end(), cmp);
    /*for (int i = 0; i < seq.size(); i++) {
        printf("%d ", seq[i]);
    }*/
    int start = 0;
    for (int i = 0; i < seq.size(); i++) {
        if (cross(seq[i], seq[(i+1) % seq.size()]) < 0) {
            start = (i+1) % seq.size();
        }
    }
    for (int k = 0; k < seq.size(); k++) {
        int i = start + k;
        //printf("! %d\n", seq[i % seq.size()]);
        if (fin(seq[i % seq.size()]) != fin(seq[(i + 1) % seq.size()])) {
            un(seq[i % seq.size()], seq[(i + 1) % seq.size()]);
            ops.push_back(make_pair(seq[i % seq.size()], seq[(i + 1) % seq.size()]));
            swap(a[seq[i % seq.size()]], a[seq[(i + 1) % seq.size()]]);
        }
    }
    while (a[root] != root) {
        ops.push_back(make_pair(root, a[root]));
        swap(a[root], a[a[root]]);
    }
    printf("%d\n", (int)ops.size());
    for (int i = 0; i < ops.size(); i++) {
        printf("%d %d\n", ops[i].first, ops[i].second);
    }
    return 0;
}