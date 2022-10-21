#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        string str;
        map<char, int> mp;
        cin >> str;
        for(char c : str) mp[c]++;
        int mx = max({mp['R'], mp['P'], mp['S']});
        char x = (mp['R'] == mx ? 'P' : (mp['P'] == mx ? 'S' : 'R'));
        rep(i, 0, sz(str)) cout << x;
        cout << '\n';
    }
}