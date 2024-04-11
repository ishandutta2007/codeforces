#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 1e5 + 13;
const int LOGN = 20;
const int A = 27;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    vector<int> b, c;
    for(int i = 0; i < n; i++) {
        if(i == 0 || a[i - 1] != a[i]) {
            b.push_back(a[i]);
        } else {
            c.push_back(a[i]);
        }
    }

    for(auto x : b)
        cout << x << ' ';
    for(auto x : c)
        cout << x << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}