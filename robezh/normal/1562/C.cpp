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

int find_zero() {
    rep(i, 0, n) {
        if(str[i] == '0') return i;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> str;
        if(n % 2 == 1) {
            n--;
            str.pop_back();
        }
        int z = find_zero();
        if(z == -1) {
            cout << 1 << " " << n << " " << 1 << " " << n / 2 << '\n';
        } else if(z < n / 2) {
            z++;
            cout << z << " " << n << " " << z + 1 << " " << n << '\n';
        } else {
            z++;
            cout << 1 << " " << z << " " << 1 << " " << z - 1 << '\n';
        }
    }





}