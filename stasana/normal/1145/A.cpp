#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <array>

using namespace std;

int f(vector<int> a) {
    if (is_sorted(a.begin(), a.end())) {
        return a.size();
    }
    vector<int> left, right;
    for (int i = 0; i < a.size() / 2; ++i) {
        left.emplace_back(a[i]);
    }
    for (int i = a.size() / 2; i < a.size(); ++i) {
        right.emplace_back(a[i]);
    }
    return max(f(left), f(right));
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << f(a);
    return 0;
}