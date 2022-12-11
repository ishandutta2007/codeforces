#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;
typedef long double ld;

template<class T>
T input() {
    T value;
    cin >> value;
    return value;
}

void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

int main() {
    start();
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    vector<int> id(k);
    ll sum = 0;
    for (int i = 0; i < k; ++i) {
        id[i] = a[n - i - 1].second;
        sum += a[n - i - 1].first;
    }
    cout << sum << endl;
    id.push_back(-1);
    sort(id.begin(), id.end());
    for (int i = 1; i <= k; ++i) {
        if (i == k) {
            cout << n - id[i - 1] - 1;
        }
        else {
            cout << id[i] - id[i - 1] << " ";
        }
    }
    cout << endl;
    //system("pause");
    return 0;
}