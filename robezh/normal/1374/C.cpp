#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        string str;
        int n; cin >> n;
        cin >> str;
        int mn = 0, cur = 0;
        for(char c : str) {
            cur += (c == ')' ? 1 : -1);
            mn = max(cur, mn);
        }
        cout << mn << "\n";
    }

}