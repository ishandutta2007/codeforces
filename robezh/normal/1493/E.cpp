#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;

void inc(string &s) {
    int x = n - 1;
    while(x >= 0 && s[x] == '1') x--;
    assert(x >= 0);
    s[x] = '1';
    x++;
    while(x < n) s[x++] = '0';
}

int getdist(string s, string t) {
    int cnt = 0;
    while(cnt < 5 && s < t) inc(s), cnt++;
    return cnt;
}

string getxor(string s1, string s2) {
    string res = s1;
    rep(i, 0, n) res[i] = char(((s1[i] - '0') ^ (s2[i] - '0')) + '0');
    return res;
}

string L, R;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> L >> R;
    string res;
    if(getdist(L, R) <= 4) {
        string res(n, '0');
        for(string i = L; ; inc(i)) {
            string cur(n, '0');
            for(string j = i; ;inc(j)) {
                cur = getxor(cur, j);
                res = max(res, cur);
                if(j == R) break;
            }
            if(i == R) break;
        }
//        cout << "?" << endl;
        cout << res << "\n";
        return 0;
    } else if(L[0] != R[0]) {
        rep(i, 0, n) cout << 1;
        cout << '\n';
    } else {
        R[n - 1] = '1';
        cout << R << '\n';
    }



}