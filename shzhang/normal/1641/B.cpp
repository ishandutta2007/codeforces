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

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

int a[505];
vector<pair<int, int> > ops;
int addval = 0;
vector<int> ans;

void solve(vector<int>& seq)
{
    if (seq.empty()) return;
    int pos = 0;
    for (int i = 1; i < seq.size(); i++) {
        if (seq[i] == seq[0]) {
            pos = i; break;
        }
    }
    for (int i = 1; i < pos; i++) {
        ops.push_back(make_pair(seq[i], pos + i + addval));
    }
    ans.push_back(2 * pos); addval += 2 * pos;
    vector<int> seq2;
    for (int i = pos - 1; i >= 1; i--) seq2.push_back(seq[i]);
    for (int i = pos + 1; i < seq.size(); i++) seq2.push_back(seq[i]);
    solve(seq2);
}

void work()
{
    map<int, int> freq;
    int n; scanf("%d", &n);
    vector<int> seq;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i); seq.push_back(a[i]);
    }
    for (int i = 1; i <= n; i++) {
        freq[a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (freq[a[i]] % 2) {
            printf("-1\n"); return;
        }
    }
    ops.clear(); addval = 0; ans.clear();
    solve(seq);
    printf("%d\n", (int)ops.size());
    for (int i = 0; i < ops.size(); i++) {
        printf("%d %d\n", ops[i].second, ops[i].first);
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}