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
#define int long long
const int N = (int) 3e5 + 5, mod = (int) 0;
int need[N];
pair<int, int> sr[N];
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n; n--;
    int have = 0, tttt;
    cin >> have >> tttt;
    for (int i = 0; i < n; ++i) {
        cin >> sr[i].first >> sr[i].second;
    }
    sort(sr, sr + n);
    reverse(sr, sr + n);
    int ed = 0;
    for (int i = 0; i < n; ++i)
        need[i] = sr[i].second - sr[i].first + 1;
    int res = 1e9;
    multiset<int> st;
    for (int f = 0; f <= n; ++f) {
        while (sr[ed].first > have) {
            st.insert(need[ed]);
            ed++;
        }
        res = min(res, ed + 1 - f);
        if (f == n) break;
        int flag = 0;
        if ((int) st.size()) {
            auto x = st.begin();
            int val = *x;
            if (have < val) {
                flag = 1;
                break;
            }
            have -= val;
            st.erase(x);
        } else break;
        if (flag) break;
        
    }
    cout << res << endl;
}