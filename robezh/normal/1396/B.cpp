#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

int n;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        int mx = 0, sum = 0;
        rep(i, 0, n) {
            int a; cin >> a;
            mx = max(mx, a);
            sum += a;
        }
        if(mx * 2 > sum) {
            cout << "T" << '\n';
        } else {
            if(sum % 2 == 0) cout << "HL\n";
            else cout << "T\n";
        }
    }



}