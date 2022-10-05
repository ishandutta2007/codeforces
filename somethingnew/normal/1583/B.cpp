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
    vector<int> ex(n, 1);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        ex[b-1] = 0;
    }
    for (int j = 0; j < n; ++j) {
        if (ex[j]) {
            for (int i = 0; i < n; ++i) {
                if (i != j)
                    cout << i + 1 << ' ' << j + 1 << '\n';
            }
            return;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}