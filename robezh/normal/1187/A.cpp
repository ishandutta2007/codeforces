#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int s, t, n;

int main() {
    int T;
    cin >> T;
    while(T--) {
        cin >> n >> s >> t;
        int both = s + t - n;
        int res = max(s - both + 1, t - both + 1);
        cout << res << "\n";
    }
}