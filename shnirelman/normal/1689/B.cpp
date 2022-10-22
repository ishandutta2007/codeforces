#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 1e6 + 13;
const int K = 17;
const int M = 1e9 + 7;
const int LOGN = 20;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    set<int> st;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        st.insert(i);
    }

    if(n == 1) {
        cout << -1 << '\n';
        return;
    }

    vector<int> b(n, -1);
    for(int i = 0; i < n; i++) {
        if(*st.begin() != a[i] && (st.size() > 2 || st.size() == 1 || *next(st.begin()) != a[i + 1])) {
            b[i] = *st.begin();
            st.erase(st.begin());
        } else {
            b[i] = *next(st.begin());
            st.erase(b[i]);
        }
    }

    for(int x : b)
        cout << x + 1 << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}