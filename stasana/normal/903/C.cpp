#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    a.push_back(-1);
    sort(a.begin(), a.end());
    a.push_back(-1);
    int res = 0;
    int cnt = 0;
    for (int i = 1; i < a.size(); ++i) {
        if (a[i] != a[i - 1]) {
            res = max(res, cnt);
            cnt = 1;
        } else {
            ++cnt;
        }
    }
    cout << res;
    return 0;
}