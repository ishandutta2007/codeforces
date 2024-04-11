#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

void solve() {
    int n, k;
    cin >> n >> k;

    int m = 0;

    vector<int> a(n);
    set<int> st;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        st.insert(a[i]);
    }

    if(st.size() > k) {
        cout << -1 << endl;
        return ;
    }

    for(auto x : st)
        a.insert(a.begin(), x);

    n = a.size();

    vector<int> b;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(b.size() >= k) {
            if(b[b.size() - k] != a[i]) {
                b.push_back(b[b.size() - k]);
                cnt++;
                i--;

                if(cnt >= n + 3) {
                    cout << -1 << endl;
                    return;
                }
                continue;
            }
        }

        b.push_back(a[i]);
        cnt = 0;
    }

    cout << b.size() << endl;
    for(auto x : b)
        cout << x << ' ';
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}