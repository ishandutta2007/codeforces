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
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> ex(n * 3, 1);
    vector<int> edg;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        if (ex[a] and ex[b]) {
            edg.push_back(i + 1);
            ex[a] = 0;
            ex[b] = 0;
        }
    }
    if (edg.size() >= n) {
        cout << "Matching\n";
        for (int i = 0; i < n; ++i) {
            cout << edg[i] << ' ';
        }
    } else {
        int cnt = n;
        cout << "IndSet\n";
        for (int i = 0; i < 3 * n; ++i) {
            if (cnt == 0)
                break;
            if (ex[i]) {
                cout << i + 1 << ' ';
                cnt--;
            }
        }
    }
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}