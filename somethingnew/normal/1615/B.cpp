#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#define int long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
void solve() {
    int n;
    cin >> n;
    int sm = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        sm += x;
    }
    if (sm % n == 0)
        cout << "0\n";
    else
        cout << "1\n";
}
signed main() {
    vector<vector<int>> bitcnt(2e5 + 5, vector<int>(30));
    for (int i = 1; i < bitcnt.size(); ++i) {
        bitcnt[i] = bitcnt[i - 1];
        for (int j = 0; j < 30; ++j) {
            if (i & (1 << j)) {
                bitcnt[i][j]++;
            }
        }
    }
    int n;
    cin >> n;
    while (n--) {
        int l, r;
        cin >> l >> r;
        l--;
        vector<int> res = bitcnt[r];
        int mx = 0;
        for (int i = 0; i < 30; ++i) {
            mx = max(mx, res[i] - bitcnt[l][i]);
        }
        cout << (r - l) - mx << '\n';
    }
}