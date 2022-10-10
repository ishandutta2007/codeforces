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

        string t;
        t = s;
        reverse(t.begin(), t.end());
        if(s != t) {
            int pairs = 0;
            for(int i = 0; i < n - 1 - i; i++)
                if(s[i] != s[n - 1 - i])
                    pairs++;

            int cnt = 0;
            for(auto c : s)
                cnt += (c == '0');

            if((n % 2 && s[n/2] == '0' && pairs == 1 && cnt == 2)) {
                cout << "DRAW\n";
            }
            else
                cout << "ALICE\n";
            continue;
        }

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