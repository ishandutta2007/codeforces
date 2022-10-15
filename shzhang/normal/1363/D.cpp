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

int n, k;
vector<int> subset[1005];

int ask(vector<int>& query)
{
    printf("? %d ", (int)query.size());
    for (int i = 0; i < query.size(); i++) {
        printf("%d ", query[i]);
    }
    printf("\n");
    fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

int askprefix(int len)
{
    vector<int> seq;
    for (int i = 1; i <= len; i++) seq.push_back(i);
    return ask(seq);
}

void work(void)
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; i++) {
        int c; scanf("%d", &c);
        subset[i].clear();
        for (int j = 1; j <= c; j++) {
            int v; scanf("%d", &v); subset[i].push_back(v);
        }
        sort(subset[i].begin(), subset[i].end());
    }
    int smax = askprefix(n);
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (askprefix(mid) == smax) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    vector<int> ans;
    for (int i = 1; i <= k; i++) {
        int haspos = false;
        for (int j = 0; j < subset[i].size(); j++) {
            if (subset[i][j] == l) haspos = true;
        }
        if (!haspos) {
            ans.push_back(smax);
        } else {
            subset[i].push_back(n + 1);
            vector<int> qry;
            int pre = 0;
            for (int j = 0; j < subset[i].size(); j++) {
                for (int K = pre + 1; K < subset[i][j]; K++) {
                    qry.push_back(K);
                }
                pre = subset[i][j];
            }
            ans.push_back(ask(qry));
        }
    }
    printf("! ");
    for (int i = 0; i < k; i++) printf("%d ", ans[i]);
    printf("\n"); fflush(stdout);
    char resp[15]; scanf("%s", resp);
    if (resp[0] != 'C') {
        exit(0);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}