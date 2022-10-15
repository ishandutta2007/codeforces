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
ll a[100005];

bool cmp(pair<ll, ll> pa, pair<ll, ll> pb)
{
    return pa.first * pb.second < pa.second * pb.first;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    if (n == 1) {
        printf("0\n"); return 0;
    }
    int maxkeep = 0;
    for (int d = -330; d <= 330; d++) {
        vector<ll> vec;
        for (int i = 1; i <= n; i++) vec.push_back(a[i] - i * d);
        sort(vec.begin(), vec.end());
        int currun = 0;
        for (int i = 0; i < vec.size(); i++) {
            if (i == 0 || vec[i] != vec[i-1]) currun = 1;
            else currun++;
            maxkeep = max(maxkeep, currun);
        }
    }
    vector<ll> vec;
    for (int i = 1; i <= n; i++) {
        vec.clear();
        for (int j = i + 1; j < i + 330 && j <= n; j++) {
            if ((a[j] - a[i]) % (ll)(j - i)) continue;
            vec.push_back((a[j] - a[i]) / (ll)(j - i));
            //printf("! %lld, ")
        }
        sort(vec.begin(), vec.end());
        int currun = 0;
        for (int k = 0; k < vec.size(); k++) {
            if (k == 0 || vec[k] != vec[k-1]) currun = 1;
            else currun++;
            //if (currun == 3) printf("! %d ", i);
            maxkeep = max(maxkeep, currun + 1);
        }
    }
    printf("%d", n - maxkeep);
    return 0;
}