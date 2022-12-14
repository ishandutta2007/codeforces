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

const int N = (int) 65, M = 1e6 + 5, mod = (int) 0;
map<set<int>, int> mp;
set<int> st[M];
vector<int> all[N];
int cnt, sum[M], dp[N], g[M];
int gr[] = {0, 1,1,2,2,2,3,3,3,3,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,10};
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 /*   all[0].push_back(cnt);
    cnt++;
    for (int add = 1; add <= 60; ++add) {
        for (int cur = 60; cur >= add; --cur) {
            for (int x : all[cur - add]) {
                st[cnt] = st[x];
                st[cnt].insert(add);
                sum[cnt] = cur;
                mp[st[cnt]] = cnt;
                all[cur].push_back(cnt);
                cnt++;
            }
        }
    }
    for (int s = 1; s <= 60; ++s) {
        memset(g, 0, sizeof g);
        for (int amount = s; amount >= 0; --amount) for (int c : all[amount]) {
            if (sum[c] > s) continue;
            int rem = s - sum[c];
            set<int> mex;
            for (int choose = 1; choose <= rem; ++choose) {
                if (st[c].find(choose) == st[c].end()) {
                    set<int> snx = st[c];
                    snx.insert(choose);
                    int nxid = mp[snx];
                    mex.insert(g[nxid]);
                }
            }
       //     cout << " hi " << c << ' ' << s << ' ' << (int) mex.size() << ' ' << sum[c] << endl;
            while (mex.find(g[c]) != mex.end()) g[c]++;
        }
        gr[s] = g[0];
    }
    cout << "{";
    for (int j = 1; j <= 60; ++j) {
        if (j != 1) cout << ",";
        cout << gr[j];
    }
    cout <<"}";*/
    int n, res = 0;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
 //       cout << " hi " << gr[x] << endl;
        res ^= gr[x];
    }
    cout << (res != 0? "NO": "YES");
}