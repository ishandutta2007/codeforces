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
#include "queue"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> tabl(n, vector<int>(n));
    if (n == 2) {
        cout << "-1\n";
        return;
    }
    vector<int> a, b;
    for (int i = 1; i <= n * n / 2; ++i) {
        a.push_back(i);
    }
    for (int i = n * n / 2 + 1; i <= n * n; ++i) {
        b.push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i + j) % 2) {
                tabl[i][j] = a.back();
                a.pop_back();
            } else {
                tabl[i][j] = b.back();
                b.pop_back();
            }
        }
    }
    for (auto i : tabl){
        for (auto j : i)
            cout << j << ' ';
        cout << '\n';
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    int n = 1;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}