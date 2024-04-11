#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < 6; i++) {
        v.push_back((n & 1));
        n /= 2;
    }
    int x = 0;
    vector<int> ord = {5, 0, 2, 3, 1, 4};
    for(auto p : ord) {
        x *= 2;
        x += v[p];
    }
    cout << x << '\n';
}