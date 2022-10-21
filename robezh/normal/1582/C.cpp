#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = (int)1e5 + 50, INF = (int)1e9 + 50;

int n;
string str;

int solve(char c) {
    int l = 0, r = n - 1;
    int res = 0;
    while(true) {
        int cntl = 0, cntr = 0;
        while(l < n && str[l] == c) {
            cntl++;
            l++;
        }
        while(r >= 0 && str[r] == c) {
            cntr++;
            r--;
        }
        if(l > r) break;
        if(str[l] != str[r]) return INF;
        res += max(cntl, cntr) - min(cntl, cntr);
        l++;
        r--;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        cin >> str;
        int res = INF;
        for (char c = 'a'; c <= 'z'; c++) {
            res = min(solve(c), res);
        }
        if(res == INF) res = -1;
        cout << res << '\n';
    }
}