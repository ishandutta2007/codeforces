#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        cin >> s;
        int x = 0, y = 0;
        map<pair<int, int>, int> prv;
        prv[{0, 0}] = 0;
        int l = -1, r = -1, cu = 0;
        for(auto c : s) {
            cu++;
            if(c == 'U')
                y++;
            if(c == 'D')
                y--;
            if(c == 'R')
                x++;
            if(c == 'L')
                x--;
            if(prv.count({x, y})) {
                int L = prv[{x, y}];
                if(l == -1 || cu - L < r - l) {
                    r = cu;
                    l = L + 1;
                }
            }
            prv[{x, y}] = cu;
        }
        if(l == -1)
            cout << "-1\n";
        else
            cout << l << " " << r << '\n';
    }
}