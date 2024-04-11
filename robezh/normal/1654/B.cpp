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
        string str;
        cin >> str;
        map<char, int> mp;
        int l = sz(str);
        for (int i = sz(str) - 1; i >= 0; i--) {
            if (!mp[str[i]]) l = i;
            mp[str[i]] = 1;
        }
        cout << str.substr(l) << '\n';
    }
}