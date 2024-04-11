#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
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
        int a = 0, b = 0;
        for(int i = 0; i < sz(str); i++) {
            if(i % 2 == 0) a *= 10, a += str[i] - '0';
            else b *= 10, b += str[i] - '0';
        }
        cout << 1LL * (a + 1) * (b + 1) - 2 << '\n';
    }

}