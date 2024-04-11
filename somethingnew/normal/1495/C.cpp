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
void print(vector<string> &pole) {
    for (auto &i : pole)
        cout << i << '\n';
}
void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> pole(n);
    for (int i = 0; i < n; ++i) {
        cin >> pole[i];
    }
    int k = 0;
    while (k + 3 < n) {
        for (int i = 0; i < m; ++i) {
            pole[k][i] = 'X';
        }
        bool br = 0;
        for (int j = 0; j < m; ++j) {
            if (pole[k + 2][j] == 'X' or pole[k + 1][j] == 'X') {
                pole[k + 1][j] = 'X';
                pole[k + 2][j] = 'X';
                br = 1;
                break;
            }
        }
        if (br == 0){
            pole[k + 1][0] = pole[k + 2][0] = 'X';
        }
        k += 3;
    }
    if (n - k <= 2) {
        for (int i = 0; i < m; ++i) {
            pole[k][i] = 'X';
        }
        return print(pole);
    }
    if (n - k == 3) {
        for (int i = 0; i < m; ++i) {
            pole[k][i] = 'X';
        }
        for (int j = 0; j < m; ++j) {
            if (pole[k + 2][j] == 'X') {
                pole[k + 1][j] = 'X';
            }
        }
        return print(pole);
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