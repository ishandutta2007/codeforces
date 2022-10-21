#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        string str;
        cin >> str;
        reverse(all(str));
        if(sz(str) == 2) cout << str[0] << '\n';
        else {
            int mn = 10;
            for (int i = 0; i < sz(str); i++) {
                mn = min(str[i] - '0', mn);
            }
            cout << mn << '\n';
        }

    }
}