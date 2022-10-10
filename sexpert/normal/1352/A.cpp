#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        vector<int> v;
        int n, x = 1;
        cin >> n;
        while(n) {
            if(n % 10)
                v.push_back(x * (n % 10));
            x *= 10;
            n /= 10;
        }
        cout << v.size() << '\n';
        for(auto x : v)
            cout << x << " ";
        cout << '\n';
    }
}