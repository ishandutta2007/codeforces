// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;

const int N = (int) 1e6 + 6, mod = (int) 0;
#define count lets_count
int pl(int x, vector<int> &a) { return lower_bound(a.begin(), a.end(), x) - a.begin(); }
int ssz, mn[N << 2], xl[N], xr[N], yl[N], yr[N], cnt[N << 2], ch[N << 2];
vector<int> ax, ay;
void build(int v = 1, int b = 0, int e = ssz) {
    ch[v] = cnt[v] = mn[v] = 0;
    if (b + 1 == e) {
        cnt[v] = ay[b + 1] - ay[b];
        return;
    }
    int m = b + e >> 1, l = v << 1, r = l | 1;
    build(l, b, m);
    build(r, m, e);
    cnt[v] = cnt[l] + cnt[r];
}

void update(int i, int j, int x, int v = 1, int b = 0, int e = ssz) {
    if (i >= e || b >= j) return;
    if (i <= b && e <= j) {
        ch[v] += x;
        mn[v] += x;
        return;
    }
    int m = b + e >> 1, l = v << 1, r = l | 1;
    update(i, j, x, l, b, m);
    update(i, j, x, r, m, e);
    mn[v] = min(mn[l], mn[r]);
    cnt[v] = (mn[l] == mn[v]? cnt[l]: 0) + (mn[r] == mn[v]? cnt[r]: 0);
    mn[v] += ch[v];
}

long long count(int m) {
    ax.clear();
    ay.clear();
    vector<pair<int, int>> event;
    for (int j = 0; j < m; ++j) {
        ax.push_back(xl[j]);
        ax.push_back(xr[j]);
        ay.push_back(yl[j]);
        ay.push_back(yr[j]);
        if (xl[j] != xr[j]) { 
            event.push_back(make_pair(xl[j], j));
            event.push_back(make_pair(xr[j], j));
        }
    }
    sort(ax.begin(), ax.end());
    ax.resize(unique(ax.begin(), ax.end()) - ax.begin());
    sort(ay.begin(), ay.end());
    ay.resize(unique(ay.begin(), ay.end()) - ay.begin());
    sort(event.begin(), event.end());
    ssz = (int) ay.size() - 1;
    if (!ssz) return 0;
    build();
    long long res = 0;
    for (int ei = 0, last = 0; ei < (int) event.size(); last = event[ei].first, ++ei) {
        int x = event[ei].first, j = event[ei].second;
        res += (x - last) * 1ll * (mn[1] == 0? ay[ssz] - ay[0] - cnt[1]: ay[ssz] - ay[0]);
        if (xl[j] == x) {
            update(pl(yl[j], ay), pl(yr[j], ay), +1);
        } else {
            update(pl(yl[j], ay), pl(yr[j], ay), -1);
        }       
    }
    return res;
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        cin >> xl[i] >> yl[i] >> xr[i] >> yr[i];
        xl[i]--;
        yl[i]--;
    }
    for (long long len = 1, last = 0; len <= k; len <<= 1) {
        long long cnt = count(m);
        if (cnt & 1) {
            cout << "Hamed\n";
            return 0;
        }
        last = cnt;
        for (int j = 0; j < m; ++j) {
            xl[j] >>= 1;
            xr[j] >>= 1;
            yl[j] >>= 1;
            yr[j] >>= 1;
        }
    }
    cout << "Malek\n";
}