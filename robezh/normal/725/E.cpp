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
const int N = (int)2e5 + 50;

int n, c[N], ct;
int cnt[N], to[N];

bool solve(int ad) {
    cnt[ad]++;
    int cur = ct, rem = ct;
    while(true) {
        int nxt = to[min(rem, cur)];
        if(ad <= cur && ad >= nxt) nxt = ad;
        if(nxt == 0) break;
        int tk = min(rem / nxt, cnt[nxt]);
        rem -= nxt * tk;
        cur = nxt - 1;
    }
    cnt[ad]--;
    return rem == 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> ct >> n;
    rep(i, 0, n) {
        cin >> c[i]; cnt[c[i]]++;
    }
    for(int i = 1; i <= ct; i++) {
        if(!cnt[i]) to[i] = to[i - 1];
        else to[i] = i;
    }
    rep(i, 1, ct + 1) {
        if(!solve(i)) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << "Greed is good\n";
}