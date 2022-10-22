#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> data(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    sort(data.begin(), data.end());
    vector <int> ans(n, 0);
    int it1 = 0, it2 = n - 1;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            ans[i] = data[it1];
            it1++;
        } else {
            ans[i] = data[it2];
            it2--;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
}