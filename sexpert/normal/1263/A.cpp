#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        vector<int> a(3);
        for(auto &x : a)
            cin >> x;
        sort(a.begin(), a.end());
        if(a[0] + a[1] <= a[2])
            cout << a[0] + a[1] << '\n';
        else
            cout << (a[0] + a[1] + a[2])/2 << '\n';
    }
}