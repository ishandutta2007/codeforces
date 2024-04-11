#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 1e5 + 13;
const int LOGN = 30;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt += a[i] == 0;
    }


    set<int> st(a.begin(), a.end());

    if(*st.begin() == 0) {
        cout << n - cnt << endl;
    } else if(st.size() != n) {
        cout << n << endl;
    } else {
        cout << n + 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}