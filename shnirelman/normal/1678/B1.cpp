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

    string s;
    cin >> s;

    vector<int> a(1, 1);
    for(int i = 1; i < n; i++) {
        if(s[i] == s[i - 1])
            a.back()++;
        else
            a.push_back(1);
    }

    int ans = 0;
    for(int i = 0; i < a.size(); i++) {
        if(a[i] % 2 != 0) {
            a[i]++;
            a[i + 1]--;
            ans++;
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}