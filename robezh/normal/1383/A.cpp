#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 20;

int n;
set<int> to[N];

int solve() {
    n = 20;
    rep(i, 0, n) to[i].clear();
    int len; cin >> len;
    string a, b; cin >> a >> b;
    rep(i, 0, len) {
        if(a[i] > b[i]) return -1;
        else if(a[i] < b[i]) {
            to[a[i] - 'a'].insert(b[i] - 'a');
//            cout << "adding " << int(a[i] - 'a') << " " <<
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(!to[i].empty()) {
            int fir = *to[i].begin();
            for(int nxt : to[i]) {
                if(fir != nxt) to[fir].insert(nxt);
            }
            to[i].clear();
            ans++;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cout << solve() << '\n';
    }


}