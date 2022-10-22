#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<li, li>;

const int INF = 1e9 + 14;
const int M = 998244353;
const int N = 2e5 + 13;

/*
1
3 2
101
*/

void solve() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<int> a;
    for(int i = 0; i < n; i++)
        if(s[i] == '1')
            a.push_back(i);

    for(int i = 0; i < n; i++) {
        auto it = lower_bound(a.begin(), a.end(), i);
        int y = (it == a.end() ? -1 : *it);
        int x = n;
        if(it != a.begin()) {
            it--;
            x = *it;
        }

//        cout << endl << x << ' ' << y << endl;

        if((x < n && x + m >= i && (y == -1 || y - m > i)) ||
           (y > -1 && y - m <= i && (x == n || x + m < i)) ||
            (x < n && y > -1 && x + m >= i && y - m <= i && i - x != y - i))
            cout << '1';
        else
            cout << '0';
    }

    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}