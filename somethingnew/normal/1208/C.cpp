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
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int st = 128;
    vector<vector<int>> table(n, vector<int>(n));
    for (int k = 0; k * 4 < n; ++k) {
        for (int kj = 0; kj * 4 < n; ++kj) {
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    table[i + k * 4][j + kj * 4] = i * 4 + j + k * n * 4 + kj * 16;
                    //cout << ((i * n + j) % (st * 2) / st) << ' ';
                }
                //cout << '\n';
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << table[i][j] << ' ';
        }
        cout << '\n';
    }
}