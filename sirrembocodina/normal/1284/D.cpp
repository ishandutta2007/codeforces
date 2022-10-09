//https://www.spoj.com/problems/KQUERYO/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <utility>
#include <set>
#include <stack>
#include <iterator>

using namespace std;

int n;

void solve(vector<int>& l1, vector<int>& r1, vector<int>& l2, vector<int>& r2) {
    vector<pair<int, pair<int, int> > > q;
    for (int i = 0; i < n; ++i) {
        q.push_back(make_pair(l1[i], make_pair(1, i)));
        q.push_back(make_pair(r1[i], make_pair(0, i)));
    }
    sort(q.begin(), q.end());
    multiset<int> s;
    for (int i = 0; i < q.size(); ++i) {
        int ind = q[i].second.second;
        if (q[i].second.first == 0) {
            s.insert(l2[ind]);
            s.insert(r2[ind] - 1);
        } else {
            auto it = s.lower_bound(l2[ind]);
            if (it != s.end() && *it < r2[ind]) {
                cout << "NO" << endl;
                exit(0);
            }
        }
    }
    s.clear();
    for (int i = (int) (q.size()) - 1; i >= 0; --i) {
        int ind = q[i].second.second;
        if (q[i].second.first == 1) {
            s.insert(l2[ind]);
            s.insert(r2[ind] - 1);
        } else {
            auto it = s.lower_bound(l2[ind]);
            if (it != s.end() && *it < r2[ind]) {
                cout << "NO" << endl;
                exit(0);
            }
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<int> l1(n), r1(n), l2(n), r2(n);
    for (int i = 0; i < n; ++i) {
        cin >> l1[i] >> r1[i] >> l2[i] >> r2[i];
        r1[i]++;
        r2[i]++;
    }
    solve(l1, r1, l2, r2);
    solve(l2, r2, l1, r1);
    cout << "YES" << endl;
    return 0;
}