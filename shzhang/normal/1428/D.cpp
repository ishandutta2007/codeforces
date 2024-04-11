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

int a[100005];
int row[100005];

int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    if (a[n] > 1) {
        printf("-1\n"); return 0;
    }
    vector<pair<int, int> > ans;
    vector<int> onepos;
    int currow = n;
    vector<int> threepos;
    int bot_left = 0;
    int last_3 = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 3) last_3 = i;
    }
    if (last_3) {
        int twopos = 0;
        int any_onepos = 0, Onepos = 0;
        for (int i = last_3 + 1; i <= n; i++) {
            if (a[i] == 2) twopos = i;
            if (a[i] == 1) {
                any_onepos = i;
                if (twopos) Onepos = i;
            }
        }
        if (twopos && Onepos) {
            int A = twopos; int b = Onepos;
            ans.push_back(make_pair(n, A));
            ans.push_back(make_pair(n, b));
            bot_left = A;
            a[A] = a[b] = 0;
            currow--;
        } else if (any_onepos) {
            ans.push_back(make_pair(n, any_onepos));
            currow--;
            bot_left = any_onepos;
            a[any_onepos] = 0;
        }
    }
    for (int i = n; i >= 1; i--) {
        if (a[i] == 1) {
            onepos.push_back(i);
            row[i] = currow;
            ans.push_back(make_pair(currow, i));
            currow--;
        } else if (a[i] == 2) {
            if (onepos.empty()) {
                printf("-1\n"); return 0;
            }
            ans.push_back(make_pair(row[onepos.back()], i));
            onepos.pop_back();
        } else if (a[i] == 3) {
            threepos.push_back(i);
        }
    }
    sort(threepos.begin(), threepos.end());
    if (threepos.size()) {
        if (!bot_left) {
            printf("-1\n"); return 0;
        }
        ans.push_back(make_pair(currow, last_3));
        ans.push_back(make_pair(currow, bot_left));
        currow--;
        for (int i = (int)threepos.size() - 2; i >= 0; i--) {
            ans.push_back(make_pair(currow, threepos[i]));
            ans.push_back(make_pair(currow, threepos[i+1]));
            currow--;
        }
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0;
}