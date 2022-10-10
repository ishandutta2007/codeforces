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
        string s;
        cin >> s;
        int tot = 0;
        for(auto &c : s)
            tot += (c == '0');
        if(n % 2 == 1 && s[n/2] == '0' && tot > 1) {
            cout << "ALICE\n";
            continue;
        }
        cout << "BOB\n";
    }
}