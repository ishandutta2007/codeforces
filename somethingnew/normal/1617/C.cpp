#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#include "array"
#define all(a) (a).begin(), (a).end()
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b;
    vector<int> ex(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] <= n and ex[a[i]] == 0) {
            ex[a[i]] = 1;
        } else {
            b.push_back(a[i]);
        }
    }
    sort(all(b));
    int ind = 0;
    for (int i = 1; i <= n; ++i) {
        if (ex[i] == 0) {
            if (b[ind] <= i * 2) {
                cout << "-1\n";
                return;
            }
            ind++;
        }
    }
    cout << b.size() << '\n';
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    while (n--)
        solve();
}
/*
1 2
RL
DU
LR
10
v 1 1
v 1 2
v 1 3
v 2 1
v 2 2
v 2 3
h 1 1
h 2 1
h 3 1
h 4 1

 */