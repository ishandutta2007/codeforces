#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2000 + 13;
const int K = 30;
const int M = 1e9 + 7;
const int LOGN = 20;
const int A = 26;

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    set<char> st(s.begin(), s.end());

    for(int i = 0; i < n; i++) {
        vector<int> c(A, 0);
        multiset<int> ms(c.begin(), c.begin() + st.size());
        for(int j = i; j <= i + A + 2 && j < n; j++) {
            int x = s[j] - 'a';
            ms.erase(ms.find(c[x]));
            c[x]++;
            ms.insert(c[x]);

            if(*ms.rbegin() - *ms.begin() > 1) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}