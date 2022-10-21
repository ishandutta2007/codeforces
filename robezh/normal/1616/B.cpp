#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        int n;
        string str;
        cin >> n >> str;
        if(n == 1) {
            cout << str + str << '\n';
        } else if(str[0] == str[1]) {
            cout << str[0] << str[0] << '\n';
        } else {
            int len = -1;
            for(int i = 0; i + 1 < sz(str); i++) {
                if(str[i] < str[i + 1]) {
                    len = i + 1;
                    break;
                }
            }
            string rev = str.substr(0, len);
            reverse(all(rev));
            cout << str.substr(0, len) + rev << "\n";
        }
    }
}