#include <bits/stdc++.h>
using namespace std;

long long y, k, n;
vector <long long> v;

int main() {
///    freopen("a.in", "r", stdin);
    cin >> y >> k >> n;
    for (long long sum = y / k * k + k; sum <= n; sum += k) {
        v.push_back(sum - y);
    }
    if (v.size()) {
        for (int i = 0; i < v.size(); i ++) cout << v[i] << ' '; cout << endl;
    }
    else cout << -1 << endl;
    return 0;
}