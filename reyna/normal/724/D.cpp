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

const int N = (int) 2e5 + 5, mod = (int) 0;
vector<int> a[N];
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m;
    cin >> m;
    string s;
    cin >> s;
    int n = (int) s.size();
    set<int> cur_st;
    for (int i = 0; i < n - m + 1; ++i) 
        cur_st.insert(i);
    for (int i = 0; i < n; ++i)
        a[s[i] - 'a'].push_back(i);
    string res = "";
    for (int i = 0; i < 26; ++i) {
        set<int> st = cur_st;
        for (int j : a[i])
            while (cur_st.lower_bound(j - m + 1) != cur_st.end()) {
                int x = *cur_st.lower_bound(j - m + 1);
                if (x <= j)
                    cur_st.erase(cur_st.lower_bound(j - m + 1));
                else
                    break;
            }
        if (cur_st.size() == 0) {
            int cur = -1;
            for (int x : st)
                if (cur < x) {
                    res += 'a' + i;
                    cur = a[i][lower_bound(a[i].begin(), a[i].end(), x + m) - a[i].begin() - 1];
                }
            cout << res << endl;
            break;
        }
        for (int j : a[i])
            res += 'a' + i;
    }
}