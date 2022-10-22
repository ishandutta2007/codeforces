#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector <int> data(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    sort(data.begin(), data.end());
    cin >> m;
    for (int i = 0; i < m; i++) {
        int sum;
        cin >> sum;
        int l = -1, r = n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (data[mid] > sum) {
                r = mid;
            } else {
                l = mid;
            }
        }
        cout << r << endl;
    }
}