#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#include "array"
#include "numeric"
#include "iomanip"
using namespace std;
const int INF = 1e9 + 179;
#define all(x) x.begin(), x.end()
bool solve(vector<string> st) {
    int n = st.size();
    set<string> bl;
    for (int i = 0; i < n; ++i) {
        string s1 = st[i];
        reverse(all(s1));
        if (st[i] == s1)
            return 1;
        if (st[i].size() == 2) {
            if (bl.find(string(1, st[i][1])) != bl.end())
                return 1;
            reverse(all(st[i]));
            if (bl.find(st[i]) != bl.end())
                return 1;
            reverse(all(st[i]));
        }
        if (st[i].size() == 3) {
            string s1 = st[i];
            reverse(all(s1));
            if (bl.find(s1) != bl.end())
                return 1;
            s1.pop_back();
            if (bl.find(s1) != bl.end())
                return 1;
        }
        bl.insert(st[i]);
    }
    return 0;
}
void solve() {
    int n;
    cin >> n;
    vector<string> st(n);
    for (int i = 0; i < n; ++i) {
        cin >> st[i];
    }
    if (solve(st)) {
        cout << "YES\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        reverse(all(st[i]));
    }
    reverse(all(st));
    if (solve(st)) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--) solve();
}