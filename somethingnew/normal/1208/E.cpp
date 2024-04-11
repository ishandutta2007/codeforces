#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std;
struct stackmax{
    vector<pair<int, int>> st;
    void add(int x) {
        if (st.empty())
            st.push_back({x, x});
        else
            st.push_back({x, max(x, st.back().second)});
    }
    int pop() {
        int val = st.back().first;
        st.pop_back();
        return val;
    }
    int getmx() {
        if (st.empty())
            return -1e10;
        return st.back().second;
    }
};
struct queuemax{
    stackmax a1, a2;
    int getmx() {
        return max(a1.getmx(), a2.getmx());
    }
    void pop() {
        if (a1.st.empty()) {
            while (!a2.st.empty()) {
                a1.add(a2.pop());
            }
        }
        a1.pop();
    }
    void add(int x) {
        a2.add(x);
    }
};
int w;
vector<int> ans;
vector<int> toadd;
void slv(vector<int> a) {
    int zeros = min(a.size() + 2ll, w - a.size());
    queuemax que;
    a.push_back(0);
    for (int i = 0; i < zeros; ++i) {
        que.add(0);
    }
    for (int i = 0; i < w; ++i) {
        if (i < a.size())
            que.add(a[i]);
        ans[i] += que.getmx();
        if (i == zeros and zeros != w - a.size() + 1) {
            toadd[i + 1] += que.getmx();
            toadd[w - a.size() + 2] -= que.getmx();
            i = w - a.size() + 1;
        }
        que.pop();
    }
}
signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n >> w;
    ans.assign(w, 0);
    toadd.assign(w + 1, 0);
    for (int i = 0; i < n; ++i) {
        int l;
        cin >> l;
        vector<int> nums(l);
        for (auto &j : nums)
            cin >> j;
        slv(nums);
    }
    int res = 0;
    for (int i = 0; i < w; ++i) {
        res += toadd[i];
        cout << ans[i] + res << ' ';
    }
}