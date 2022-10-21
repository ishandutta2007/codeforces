#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int mod = (int)1e9 + 7;

string s, r;
int x;
ll len = 0;
ll res = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> x;
        cin >> r;
        res = len = r.length();

        for(int i = 0; i < x; i++) {
            int cnt = r[i] - '0';
            if(r.size() < x) {
                ll oldlen = len;
                string g = r.substr(i + 1);
                for(int j = 0; j < cnt - 1; j++) {
                    r += g;
                }
            }
            res += 1LL * (cnt - 1) * (res - (i + 1)) % mod;
            res %= mod;
        }
        cout << (res % mod + mod) % mod << endl;
    }
}