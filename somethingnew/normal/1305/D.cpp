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
int zapr(int a, int b) {
    cout << "? " << a + 1 << ' ' << b + 1 << endl;
    int t;
    cin >> t;
    return t - 1;
}
void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> edges(n-1);
    vector<int> vert(n), ex(n, 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--;
        edges[i].second--;
        vert[edges[i].first]++;
        vert[edges[i].second]++;
    }
    for (int i = 0; i < n; ++i) {
        int l1 = -1, l2 = -1;
        for (int j = 0; j < n; ++j) {
            if (vert[j] == 1) {
                l2 = l1;
                l1 = j;
            }
        }
        if (l2 == -1) {
            for (int j = 0; j < n; ++j) {
                if (ex[j]) {
                    cout << "! " << j + 1 << endl;
                    return;
                }
            }
        }
        int v = zapr(l1, l2);
        if (v == l1 or v == l2) {
            cout << "! " << v + 1 << endl;
            return;
        }
        ex[l1] = 0;
        ex[l2] = 0;
        for (int j = 0; j < n - 1; ++j) {
            if (edges[j].first == l1 or edges[j].first == l2 or edges[j].second == l1 or edges[j].second == l2) {
                vert[edges[j].first]--;
                vert[edges[j].second]--;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    int n = 1;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}