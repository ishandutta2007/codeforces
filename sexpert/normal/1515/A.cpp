#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, x, sum = 0;
        cin >> n >> x;
        vector<int> v(n);
        for(auto &y : v) {
            cin >> y;
            sum += y;
        }
        if(sum == x) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        sum = 0;
        for(int i = 0; i < n; i++) {
            if(sum + v[i] == x) {
                cout << v[i + 1] << " " << v[i] << " ";
                sum += v[i];
                sum += v[i + 1];
                i++;
            }
            else {
                cout << v[i] << " ";
                sum += v[i];
            }
        }
        cout << '\n';
    }
}