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

char s[200005];

void work()
{
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    int cnt = 0;
    vector<pair<char, int> > grps;
    for (int i = 1; i <= n; i++) {
        cnt++;
        if (i == n || s[i] != s[i+1]) {
            grps.push_back(make_pair(s[i], cnt));
            cnt = 0;
        }
    }
    int ans = 0;
    while (!grps.empty()) {
        if (grps.back().first == 'A' || grps.back().second == 0) {
            grps.pop_back(); continue;
        }
        if (grps.size() == 1) {
            ans += (grps[0].second / 2) * 2; break;
        }
        int& b_amt = grps[grps.size() - 1].second;
        int& a_before = grps[grps.size() - 2].second;
        if (a_before <= b_amt) {
            ans += a_before * 2;
            b_amt -= a_before;
            grps.pop_back(); grps.pop_back();
            if (grps.size() >= 1 && grps.back().first == 'B') {
                grps[grps.size() - 1].second += b_amt;
            } else {
                grps.push_back(make_pair('B', b_amt));
            }
        } else {
            ans += b_amt * 2;
            grps.pop_back(); grps.pop_back();
        }
    }
    printf("%d\n", n - ans);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        work();
    }
    return 0;
}