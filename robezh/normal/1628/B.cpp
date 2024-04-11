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

const int N = (int)1e5 + 50;

int n;
string str[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        bool one = false;
        rep(i, 0, n) {
            cin >> str[i];
            one |= (sz(str[i]) == 1);
        }
        if(one) {
            cout << "YES\n";
            continue;
        }
        map<string, int> mp;
        bool good = false;
        rep(i, 0, n) {
            mp[str[i]]++;
            string rv = str[i];
            reverse(all(rv));
            good |= mp[rv] > 0;
            good |= mp[string() + str[i][2] + str[i][1]] > 0;
        }
        mp.clear();
        for (int i = n - 1; i >= 0; i--) {
            if(sz(str[i]) == 3) {
                good |= mp[string() + str[i][1] + str[i][0]] > 0;
            }
            mp[str[i]]++;
        }
        cout << (good ? "YES" : "NO") << '\n';
    }
}