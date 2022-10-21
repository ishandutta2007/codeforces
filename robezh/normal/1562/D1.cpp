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

const int N = (int)3e5 + 50;

int n, q;
string str;
int psum[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> q;
        cin >> str;
        str = " " + str;
        rep(i, 1, n + 1) {
            if((str[i] == '-') ^ (i % 2 == 0)) psum[i] = 1;
            else psum[i] = -1;
            psum[i] += psum[i - 1];
        }
        while(q--) {
            int l, r; cin >> l >> r;
            int d = abs(psum[r] - psum[l - 1]);
            if(d % 2 == 1) cout << 1 << "\n";
            else if(d == 0) cout << 0 << '\n';
            else cout << 2 << '\n';
        }
    }




}