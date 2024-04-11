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

int n, k;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> k;
        cin >> s;
        vi ls;
        int fir = 0;
        int cnt = k;
        int cmp = 0;
        while(fir < n && s[fir] == 'L') fir++;
        for(int i = fir; i < n; ) {
            cnt++;
            cmp++;
            int nxt = i + 1;
            while(nxt < n && s[nxt] == 'L') nxt++;
            if(nxt != n) ls.push_back(nxt - i - 1);
            i = nxt;
//            cout << nxt << endl;
        }
        sort(all(ls));
        for(int i = 0; i < sz(ls); i++) {
            if(k >= ls[i]) {
                k -= ls[i];
                cmp--;
            }
        }
        cout << max(0, min(n + n - 1, cnt + (cnt - max(1, cmp)))) << '\n';

    }

}