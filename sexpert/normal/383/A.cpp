#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ct = 0;

int main() {
    int n;
    cin >> n;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x == 1)
            ct++;
        else
            ans += ct;
    }
    cout << ans << endl;
}