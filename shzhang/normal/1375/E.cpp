#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <iostream>
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


int n;
int orig[1005];
int a[1005];

vector<pair<int, int> > ans;
int pos[1005];

set<int> locs;

void update(int x)
{
    if (x < 1 || x >= n) return;
    if (pos[x+1] < pos[x]) {
        locs.insert(x);
    } else {
        locs.erase(x);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", orig + i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (orig[j] < orig[i] || (orig[j] == orig[i] && j <= i)) {
                a[i]++;
            }
        }
        pos[a[i]] = i;
    }
    /*for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");*/
    for (int i = 1; i < n; i++) update(i);
    while (!locs.empty()) {
        auto iter = locs.begin();
        int val = *iter;
        locs.erase(iter);
        ans.push_back(make_pair(pos[val + 1], pos[val]));
        swap(pos[val], pos[val + 1]);
        update(val - 1);
        update(val);
        update(val + 1);
    }
    vector<pair<int, int> > newans;
    for (int i = 0; i < ans.size(); i++) {
        if (orig[ans[i].first] != orig[ans[i].second]) {
            newans.push_back(ans[i]);
        }
    }
    printf("%d\n", (int)newans.size());
    for (int i = 0; i < newans.size(); i++) {
        printf("%d %d\n", newans[i].first, newans[i].second);
    }
    return 0;
}