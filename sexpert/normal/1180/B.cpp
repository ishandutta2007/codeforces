#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for(auto &x : a) {
        cin >> x;
        if(x >= 0)
            x = -x - 1;
    }
    if(n % 2) {
        auto it = min_element(a.begin(), a.end());
        *it = (-*it) - 1;
    }
    for(auto x : a)
        cout << x << '\n';
}