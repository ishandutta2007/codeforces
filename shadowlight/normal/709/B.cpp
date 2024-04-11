#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, st;
    cin >> n >> st;
    vector <int> data(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    sort(data.begin(), data.end());
    if (n == 1) {
        cout << 0;
    } else if (st <= data[0]) {
        cout << data[n - 2] - st;
    } else if (st >= data[n - 1]) {
        cout << st - data[1];
    } else {
        int path1 = data[n - 2] - data[0] + min(st - data[0], abs(st - data[n - 2]));
        int path2 = data[n - 1] - data[1] + min(data[n - 1] - st, abs(st - data[1]));
        cout << min(path1, path2);
    }
}