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

int b[20];
int perm[20];

struct Elem {
    int a1;
    int a2;
    int mask;
};

Elem mk_elem(int a1, int a2, int mask)
{
    Elem elem; elem.a1 = a1; elem.a2 = a2;
    elem.mask = mask; return elem;
}

vector<Elem> seq_double(vector<Elem> orig)
{
    vector<Elem> result;
    for (int i = 0; i < orig.size(); i++) {
        Elem cur = orig[i];
        cur.mask *= 2; cur.mask += i % 2;
        result.push_back(cur);
    }
    for (int i = (int)orig.size() - 2; i >= 0; i--) {
        Elem cur = orig[i];
        cur.mask *= 2; cur.mask += (1 - (i % 2));
        result.push_back(cur);
    }
    Elem extra;
    extra.a1 = extra.a2 = 0;
    extra.mask = 1;
    result.push_back(extra);
    extra = orig[(int)orig.size() - 1];
    extra.mask *= 2; extra.mask += 1;
    result.push_back(extra);
    return result;
}

void work()
{
    int m; scanf("%d", &m);
    vector<pair<int, int> > inseq;
    for (int i = 1; i <= m; i++) {
        int val; scanf("%d", &val);
        inseq.push_back(make_pair(val, i));
    }
    sort(inseq.begin(), inseq.end());
    reverse(inseq.begin(), inseq.end());
    for (int i = 0; i < m; i++) {
        b[i+1] = inseq[i].first;
        perm[i+1] = inseq[i].second;
    }
    if (b[1] >= 4) {
        printf("-1\n"); return;
    }
    if (m == 1) {
        if (b[1] == 1) {
            printf("1\n");
        } else if (b[1] == 2) {
            printf("1\n2\n");
        } else if (b[1] == 3) {
            printf("3\n1\n2\n");
        } else {
            printf("-1\n"); return;
        }
        return;
    }
    if (m == 2) {
        if (b[1] == 1) {
            printf("0 1\n1 1\n1 0\n");
        } else if (b[1] == 2) {
            if (b[2] == 1) {
                if (perm[1] == 2) {
                    printf("0 2\n1 1\n1 0\n1 2\n0 1\n");
                } else {
                    printf("2 0\n1 1\n0 1\n2 1\n1 0\n");
                }
            } else {
                printf("0 1\n1 2\n2 0\n1 1\n0 2\n2 1\n1 0\n2 2\n");
            }
        } else if (b[1] == 3) {
            if (b[2] == 1) {
                if (perm[1] == 2) {
                    printf("1 2\n1 0\n1 3\n0 1\n0 2\n1 1\n0 3\n");
                } else {
                    printf("2 1\n0 1\n3 1\n1 0\n2 0\n1 1\n3 0\n");
                }
            } else {
                printf("-1\n"); return;
            }
        } else {
            printf("-1\n"); return;
        }
        return;
    }
    if (b[3] >= 2) {
        printf("-1\n"); return;
    }
    vector<Elem> ans;
    if (b[1] == 1) {
        ans.push_back(mk_elem(1, 0, 0));
        ans.push_back(mk_elem(1, 1, 0));
        ans.push_back(mk_elem(0, 1, 0));
        for (int i = 1; i <= m - 2; i++) {
            ans = seq_double(ans);
        }
    } else if (b[1] == 2) {
        if (b[2] == 1) {
            ans.push_back(mk_elem(0, 1, 0));
            ans.push_back(mk_elem(1, 1, 0));
            ans.push_back(mk_elem(2, 0, 0));
            ans.push_back(mk_elem(1, 0, 0));
            ans.push_back(mk_elem(2, 1, 0));
            for (int i = 1; i <= m - 2; i++) {
                ans = seq_double(ans);
            }
        } else {
            ans.push_back(mk_elem(0, 0, 1));
            ans.push_back(mk_elem(0, 1, 1));
            ans.push_back(mk_elem(1, 2, 0));
            ans.push_back(mk_elem(2, 0, 1));
            ans.push_back(mk_elem(1, 1, 0));
            ans.push_back(mk_elem(0, 2, 1));
            ans.push_back(mk_elem(2, 1, 0));
            ans.push_back(mk_elem(1, 0, 1));
            ans.push_back(mk_elem(2, 2, 0));
            ans.push_back(mk_elem(0, 1, 0));
            ans.push_back(mk_elem(1, 2, 1));
            ans.push_back(mk_elem(2, 0, 0));
            ans.push_back(mk_elem(1, 1, 1));
            ans.push_back(mk_elem(0, 2, 0));
            ans.push_back(mk_elem(2, 1, 1));
            ans.push_back(mk_elem(1, 0, 0));
            ans.push_back(mk_elem(2, 2, 1));
            for (int i = 1; i <= m - 3; i++) {
                ans = seq_double(ans);
            }
        }
    } else {
        if (b[2] == 1) {
            ans.push_back(mk_elem(2, 1, 0));
            ans.push_back(mk_elem(0, 1, 0));
            ans.push_back(mk_elem(3, 1, 0));
            ans.push_back(mk_elem(1, 0, 0));
            ans.push_back(mk_elem(2, 0, 0));
            ans.push_back(mk_elem(1, 1, 0));
            ans.push_back(mk_elem(3, 0, 0));
            for (int i = 1; i <= m - 2; i++) {
                ans = seq_double(ans);
            }
        } else {
            printf("-1\n"); return;
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        int old[20];
        old[1] = ans[i].a1;
        old[2] = ans[i].a2;
        for (int j = 0; j < m - 2; j++) {
            old[m - j] = (ans[i].mask & (1 << j)) ? 1 : 0;
        }
        int out[20];
        for (int j = 1; j <= m; j++) {
            out[perm[j]] = old[j];
        }
        for (int j = 1; j <= m; j++) {
            printf("%d ", out[j]);
        }
        printf("\n");
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}