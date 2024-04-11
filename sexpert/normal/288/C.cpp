#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> solve(int n) {
    if(n == 0)
        return {};
    int l = __lg(n), k = (1 << l);
    vector<int> v(k);
    for(int i = 0; i < k; i++)
        v[i] = k - i - 1;
    auto u = solve(n - k);
    for(auto x : u)
        v.push_back(x);
    for(int i = 0; i < n - k; i++)
        v[k - i - 1] += k;
    return v;
}

int main() {
    int n;
    cin >> n;
    n++;
    auto v = solve(n);
    ll r = (ll)n*(n - 1);
    cout << r << '\n';
    for(auto x : v)
        cout << x << " ";
    cout << '\n';
}