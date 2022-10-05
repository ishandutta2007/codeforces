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

using namespace std;
vector<pair<int, pair<int, bool>>> nums;
int solvelr(int l, int r) { // [l, r]
    if (l > r)
        return 0;
    int res = 0;
    int ll = l, rr = r + 1;
    vector<int> addl, addr;
    addl = {l};
    int cnt = 0;
    while (!addl.empty() or !addr.empty()) {
        if (!addl.empty()) {
            reverse(all(addl));
            while (!addl.empty()) {
                int v = addl.back();
                if (nums[v].second.second) {
                    cout << -1;
                    exit(0);
                }
                cnt++;
                addl.pop_back();
                res += nums[v].second.first;
                int x = nums[v].first;
                for (int i = rr - 1; i > x; --i) {
                    addr.push_back(i);
                    if (nums[i].second.second) {
                        cout << -1;
                        exit(0);
                    }
                }
                if (x > rr) {
                    cout << -1;
                    exit(0);
                }
                rr = x;
                nums[v].second.second = 1;
                nums[x].second.second = 1;
            }
        } else {
            reverse(all(addr));
            while (!addr.empty()) {
                int v = addr.back();
                if (nums[v].second.second) {
                    cout << -1;
                    exit(0);
                }
                cnt++;
                addr.pop_back();
                res += nums[v].second.first;
                int x = nums[v].first;
                for (int i = ll + 1; i < x; ++i) {
                    addl.push_back(i);
                    if (nums[i].second.second) {
                        cout << -1;
                        exit(0);
                    }
                }
                if (x < ll) {
                    cout << -1;
                    exit(0);
                }
                ll = x;
                nums[v].second.second = 1;
                nums[x].second.second = 1;
            }
        }
    }
    int ans = min(res, cnt - res) + solvelr(ll + 1, rr - 1);
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    nums.assign(2 * n, {0, {0, 0}});
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        nums[a].first = b;
        nums[b].first = a;
        nums[a].second.first = 1;
    }
    cout << solvelr(0, 2 * n - 1);
}