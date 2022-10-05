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
void solve(){
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> h(n);
    for (auto &i : h)
        cin >> i;
    vector<pair<int, int>> heap(m);
    for (int i = 0; i < m; ++i) {
        heap[i].second = i;
    }
    make_heap(all(heap));
    vector<int> ob(n);
    for (int i = 0; i < n; ++i) {
        pop_heap(all(heap));
        ob[i] = heap.back().second;
        heap.back().first -= h[i];
        push_heap(all(heap));
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << ob[i] + 1 << ' ';
    }
    cout << endl;
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}