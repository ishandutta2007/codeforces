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

vector<pair<int, int> > group_a, group_b;

void place(vector<pair<int, int> >& vec, int val)
{
    pair<int, int> pr = vec.back();
    vec.pop_back();
    printf("%d %d %d\n", val, pr.first, pr.second);
    fflush(stdout);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i + j) % 2) {
                group_a.push_back(make_pair(i, j));
            } else {
                group_b.push_back(make_pair(i, j));
            }
        }
    }
    for (int i = 1; i <= n * n; i++) {
        int a; scanf("%d", &a);
        if (group_a.empty() || group_b.empty()) {
            int val = (group_a.empty() ? 1 : 2);
            vector<pair<int, int> >& vec = (group_a.empty() ? group_b : group_a);
            vector<int> usable;
            for (int x = 1; x <= 3; x++) {
                if (x != val) usable.push_back(x);
            }
            place(vec, a == usable[0] ? usable[1] : usable[0]);
        } else {
            if (a == 1) {
                place(group_b, 2);
            } else {
                place(group_a, 1);
            }
        }
    }
    return 0;
}