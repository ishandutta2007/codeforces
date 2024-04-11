#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = (int)2e5 + 50;
int n;
string str;
int la[2][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> str;
        memset(la, -1, sizeof(la));
        n = str.length();
        ll res = 0;
        rep(i, 0, n) {
            if(str[i] == '1') la[i % 2][1] = i;
            else if(str[i] == '0') la[i % 2][0] = i;
            int mx = max({la[0][0], la[0][1], la[1][0], la[1][1]});
            if(mx == -1) res += i + 1;
            else if(mx == la[1][0] || mx == la[0][1]) res += i - max(la[0][0], la[1][1]);
            else res += i - max(la[1][0], la[0][1]);
        }
        cout << res << '\n';
    }


}