#include<iostream>
#include<vector>
#include<algorithm>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main() {
        int t;
        cin >> t;
        for (int i = 0; i < t; ++i) {
                int n;
                cin >> n;
                ll sum = 0, mx = -1e18;
                for (int j = 0; j < n; ++j) {
                        ll x;
                        cin >> x;
                        sum += x;
                        mx = max(x, mx);
                }
                cout << max(mx * (n - 1), sum + ((n - 1 - (sum % (n-1))) % (n-1))) - sum << "\n";
        }
        return 0;
}