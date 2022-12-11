#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <set>

using namespace std;

typedef long long ll;

int main() {
    int n, k, m;
    cin >> n >> k >> m;
    vector<vector<int>> a(m, vector<int>());
    for (int i = 0; i < n; ++i) {
        int j;
        cin >> j;
        a[j % m].push_back(j);
        if ((int)a[j % m].size() == k) {
            cout << "Yes" << endl;
            for (int i = 0; i < k; ++i) {
                cout << a[j % m][i] << " ";
            }
            return 0;
        }
    }
    cout << "No";
    return 0;
}