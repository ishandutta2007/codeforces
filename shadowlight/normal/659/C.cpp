#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int INF = 1e9 + 1;

int main() {
    int n, m;
    cin >> n >> m;
    vector <int> data(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    sort(data.begin(), data.end());
    data.push_back(INF);
    vector <int> ans;
    int k = 1, j = 0;
    while (m > 0) {
        for (int i = k; i < data[j]; i++) {
            m -= i;
            if (m >= 0) {
                ans.push_back(i);
            } else {
                break;
            }
        }
        k = data[j] + 1;
        j++;
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}