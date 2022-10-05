#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#include "numeric"
#include "deque"
#define int long long
using namespace std;
int zpt = 0;
vector<int> z = {3, 1, 0, 2};
vector<int> PP = {0, 1, 2, 3};
int zpr(int i) {
    /*int val = PP[i];
    vector<int> PP2(PP.size());
    for (int j = 0; j < z.size(); ++j) {
        PP2[j] = PP[z[j]];
    }
    PP = PP2;
    zpt++;
    return val;*/
    i++;
    cout << "? " << i << endl;
    int res;
    cin >> res;
    zpt++;
    res--;
    return res;
}
void solve() {
    int n;
    zpt = 0;
    cin >> n;
    /*PP.assign(n, 0);
    z.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> z[i];
        z[i]--;PP[i] = i;
    }*/
    vector<int> p(n, -1);
    for (int i = 0; i < n; ++i) {
        if (p[i] == -1) {
            int op = 1;
            int x = zpr(i);
            vector<int> nums;
            nums.push_back(x);
            int t = zpr(i);
            //cout << x << ' ' << t << ' ';
            while (t != x) {
                nums.push_back(t);
                t = zpr(i);
                //cout << t << ' ';
            }
            //cout << endl;
            //cerr << zpt << endl;
            //cout << zpt << endl;
            op = op % nums.size() + nums.size();
            for (int j = 0; j < nums.size(); ++j) {
                int nxt = (j + op) % nums.size();
                p[nums[j]] = nums[nxt];
            }
        }
    }
    cout << "! ";
    for (auto i : p)
        cout << i + 1 << ' ';
    cout << endl;
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    while (n--) solve();
}