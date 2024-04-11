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

int main()
{
    int m; scanf("%d", &m);
    vector<int> ans;
    int zerocnt = 0;
    for (int i = 1; ; i++) {
        int tmp = i;
        while (tmp % 5 == 0) {
            zerocnt++; tmp /= 5;
        }
        if (zerocnt == m) {
            ans.push_back(i);
        } else if (zerocnt > m) {
            break;
        }
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}