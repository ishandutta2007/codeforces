#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;

//int rmq[800005][20];
//int stop[100005];
int n;

/*int query(int r)
{
    int orig = r;
    for (int i = 17; i >= 0; i--) {
        if ((1 << i) > r) continue;
        if (rmq[r][i] <= rmq[orig][0] * 2) {
            r -= (1 << i);
            if (r == 0) return 0;
        }
    }
    return r;
}*/

int ans[100005];
int seq[100005];
int a[100005];

bool cmp(int x, int y)
{
    return a[x] < a[y];
}

multiset<int> stops;

int find_next(int val)
{
    if (stops.upper_bound(val) == stops.end()) {
        //printf("%d %d\n", val, *(stops.upper_bound(0)) );
        return *(stops.upper_bound(0));
    } else {
        //printf("%d %d\n", val, *(stops.upper_bound(val)) );
        return *(stops.upper_bound(val));
    }
}


int main()
{
    scanf("%d", &n);
    /*for (int i = 1; i <= n; i++) {
        scanf("%d", &(rmq[i][0]));
        rmq[n+i][0] = rmq[i][0];
        ans[i] = -1;
    }
    for (int pwr = 1; pwr < 18; pwr++) {
        for (int i = 1; i <= n * 2; i++) {
            if (i > (1<<(pwr-1))) {
                rmq[i][pwr] = max(rmq[i][pwr-1], rmq[i-(1<<(pwr-1))][pwr-1]);
            } else {
                rmq[i][pwr] = rmq[i][pwr-1];
            }
        }
    }
    for (int i = n + 1; i <= n * 2; i++) {
        stop[i-n] = (query(i) > n ? query(i) - n : query(i));
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", stop[i]);
    }*/
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i); seq[i] = i;
    }
    sort(seq + 1, seq + n + 1, cmp);
    vector<int> lows;
    for (int i = n; i >= 1; i--) {
        if (a[seq[i]] * 2 < a[seq[n]]) stops.insert(seq[i]), lows.push_back(seq[i]);
    }
    int nxt = 0;
    for (int i = n; i >= 1; i--) {
        //printf(":%d\n", seq[i]);
        while (nxt < lows.size() && a[lows[nxt]] * 2 >= a[seq[i]]) {
            stops.erase(lows[nxt]); nxt++;
        }
        if (stops.empty()) {
            ans[seq[i]] = -1; continue;
        } else {
            ans[seq[i]] = ans[find_next(seq[i])] == -1 ? -1 : ans[find_next(seq[i])] + (find_next(seq[i]) < seq[i] ? n - seq[i] + find_next(seq[i]) : find_next(seq[i]) - seq[i]);
        }
        stops.insert(seq[i]);
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    return 0;
}