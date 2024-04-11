#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + n);
    for (int i = 0; i < n + n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (a[n - 1] == a[n]) {
        cout << "NO";
    } else {
        cout << "YES";
    }
    return 0;
}