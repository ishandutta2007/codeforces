#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        string s, t;
        cin >> n >> s >> t;
        int ct = 0;
        for(int i = 0; i < n; i++) {
            ct += (s[i] > t[i]);
            ct -= (s[i] < t[i]);
        }
        if(ct > 0)
            cout << "RED\n";
        if(ct < 0)
            cout << "BLUE\n";
        if(ct == 0)
            cout << "EQUAL\n";
    }
}