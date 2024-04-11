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

int n;
vector<pair<int, int> > seq;
vector<int> stk;

int main()
{
    ll ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int a, c; scanf("%d%d", &a, &c);
        seq.push_back(make_pair(a, c));
        ans += c;
    }
    sort(seq.begin(), seq.end());
    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty() && seq[stk.back()].first <= seq[i].first + seq[i].second) stk.pop_back();
        stk.push_back(i);
    }
    reverse(stk.begin(), stk.end());
    for (int i = 0; i + 1 < stk.size(); i++) {
        ll min_p = 1000000000000LL;
        for (int j = stk[i]; j < stk[i+1]; j++) {
            min_p = min(min_p, (ll)(seq[stk[i+1]].first - seq[j].first - seq[j].second));
        }
        ans += min_p;
    }
    printf("%lld", ans);
    return 0;
}