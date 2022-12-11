#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = 1e6 + 34;
const int INF = 1e9 + 34;

int n;
string s;
set <char> st;

int c[N], k, res = N;

int main() {
    init();

    cin >> n >> s;
    for (char ch: s) {
        st.insert(ch);
    }
    int ans = st.size();
    int cur = 0;

    for (int i = 0; i < n; i++) {
        while (k < ans) {
            if (cur == n) {
                cout << res;
                return 0;
            }
            c[s[cur] + 300]++;
            if (c[s[cur] + 300] == 1)
                k++;
            cur++;
        }
        res = min(res, cur - i);
        c[s[i] + 300]--;
        if (c[s[i] + 300] == 0)
            k--;
    }

    cout << res;


    return 0;
}