#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n <= 30) {
            cout << "NO\n";
            continue;
        }
        if(n == 36)
            cout << "YES\n6 10 15 5\n";
        else if(n == 40)
            cout << "YES\n6 10 15 9\n";
        else if(n == 44)
            cout << "YES\n6 10 15 13\n";
        else
            cout << "YES\n6 10 14 " << n - 30 << '\n';
    }
}