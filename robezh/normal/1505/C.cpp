#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool check(string str) {
    rep(i, 0, sz(str) - 2) {
        if((int(str[i] - 'A') + int(str[i + 1] - 'A') - int(str[i + 2] - 'A')) % 26 != 0) return false;
    }
    return true;
}

int main() {
    string str;
    while(cin >> str) {
        cout << (check(str) ? "YES" : "NO");

    }


}