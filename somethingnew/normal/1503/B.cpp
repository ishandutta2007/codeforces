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
    vector<pair<int, int>> c1t, c2t;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i + j) % 2)
                c1t.emplace_back(i + 1, j + 1);
            else
                c2t.emplace_back(i + 1, j + 1);
        }
    }
    while (!c1t.empty() and !c2t.empty()) {
        int k;
        cin >> k;
        if (k != 1) {
            cout << 1 << ' ' << c1t.back().first << ' ' << c1t.back().second << endl;
            c1t.pop_back();
        } else {
            cout << 2 << ' ' << c2t.back().first << ' ' << c2t.back().second << endl;
            c2t.pop_back();
        }
    }
    if (c1t.empty()) {
        while (!c2t.empty()) {
            int k;
            cin >> k;
            if (k != 2) {
                cout << 2 << ' ' << c2t.back().first << ' ' << c2t.back().second << endl;
                c2t.pop_back();
            } else {
                cout << 3 << ' ' << c2t.back().first << ' ' << c2t.back().second << endl;
                c2t.pop_back();
            }
        }
    } else {
        while (!c1t.empty()) {
            int k;
            cin >> k;
            if (k != 1) {
                cout << 1 << ' ' << c1t.back().first << ' ' << c1t.back().second << endl;
                c1t.pop_back();
            } else {
                cout << 3 << ' ' << c1t.back().first << ' ' << c1t.back().second << endl;
                c1t.pop_back();
            }
        }
    }
}