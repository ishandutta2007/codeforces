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
#define int long long
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<int>> step2(100);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        int b = a;
        int cnt = 0;
        while (b % 2 == 0){
            b /= 2;cnt++;
        }
        step2[cnt].push_back(a);
    }
    int cp = 0;
    for (int i = 0; i < 100; ++i) {
        if (step2[i].size() > step2[cp].size())
            cp = i;
    }
    cout << n - step2[cp].size() << '\n';
    for (int i = 0; i < 100; ++i) {
        if (i == cp)
            continue;
        for (auto j : step2[i])
            cout << j << ' ';
    }
}