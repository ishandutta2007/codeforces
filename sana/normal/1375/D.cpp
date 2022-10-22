#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;

void solve() {
    cin >> n; 
    vi a(n), rep(n,-1), fixed(n);
    vi ans;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < n) rep[a[i]] = i;
    }

    int mex = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= n || rep[a[i]] != i) {
            ans.push_back(i);
            while (rep[mex] != -1) mex++;
            a[i] = mex;
            rep[mex] = i;
        }
    }
    
    for (int i = n-1; i >= 0; i--) if (!fixed[rep[i]] && rep[i] != i) {
        ans.push_back(i); 
        int cur = i;
        do {
            cur = a[cur];
            fixed[cur] = 1;
            ans.push_back(cur);
        } while (cur != i);
    }

    cout << ans.size() << '\n';
    for (int x : ans) cout << x+1 << " ";
    cout << '\n';
}





int t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for (cin >> t; t; t--) solve();
    return 0;
}