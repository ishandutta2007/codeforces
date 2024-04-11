#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll suml, sumr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        suml = sumr = 0;
        vector<ll> res;
        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            suml += a;
            sumr ^= a;
        }
        res.push_back(sumr);
        res.push_back(suml + sumr);
        cout << res.size() << '\n';
        cout << res[0] << " " << res[1] << '\n';
//        cout << (suml + res[0] + res[1]) << " " << (2 * (sumr ^ res[0] ^ res[1])) << '\n';
    }
}