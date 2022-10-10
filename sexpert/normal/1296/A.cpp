#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int c1 = 0;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            c1 += (x % 2);
        }
        if(c1 == 0 || (c1 == n && n % 2 == 0))
            cout << "NO\n";
        else
            cout << "YES\n";
    }   
}