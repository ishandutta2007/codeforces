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
const int N = (int)1e5 + 50;

int n;
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> str;
        n = str.length();
        int cnt0 = 0, cnt1 = 0;
        rep(i, 0, n) {
            if(str[i] == '0' && (i == 0 || str[i] != str[i - 1])) cnt0++;
            if(str[i] == '1' && (i == 0 || str[i] != str[i - 1])) cnt1++;
        }
        int res = 2;
        if(cnt0 == 0) res = 0;
        else if(cnt0 == 1) res = 1;
        cout << res << '\n';
    }



}