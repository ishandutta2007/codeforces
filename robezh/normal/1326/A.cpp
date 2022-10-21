#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        if(n == 1) cout << -1 << "\n";
        else {
            string res;
            for(int j = 0; j < n - 2; j++) res.push_back('3');
            res.push_back('2');
            res.push_back('3');
            cout << res << '\n';
        }
    }

}