#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int co, ce;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(v[i] % 2)
            ce++;
        else
            co++;
    }
    if(ce > 0 && co > 0)
        sort(v.begin(), v.end());
    for(auto x : v)
        cout << x << " ";
    cout << '\n';
}