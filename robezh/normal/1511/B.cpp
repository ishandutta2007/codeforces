#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int pw10[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;

    pw10[0] = 1;
    rep(i, 1, 10) pw10[i] = pw10[i - 1] * 10;
    while(T--) {
        int a, b, c;
        cin >> a >> b >> c;
        int ra, rb, rc;
        if(a == c || b == c) {
            cout << pw10[a - 1] << " " << pw10[b - 1] << '\n';
        } else if(a == b) {
            cout << pw10[a - 1] + pw10[c - 1] << " " << pw10[b - 1] + pw10[c - 1] * 2 << '\n';
        } else {
            cout << pw10[a - 1] << " " << pw10[b - 1] + pw10[c - 1] << '\n';
        }
    }


}