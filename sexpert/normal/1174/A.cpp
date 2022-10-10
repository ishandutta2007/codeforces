#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(2*n);
    for(auto &x : v) cin >> x;
    sort(v.begin(), v.end());
    if(v[0] == v[2*n - 1])
        cout << "-1\n";
    else {
        for(auto x : v) cout << x << " ";
        cout << '\n';
    }
}