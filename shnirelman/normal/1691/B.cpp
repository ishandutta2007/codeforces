#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 2013;
const int K = 9;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> p(n);
    for(int i = 0; i < n; ) {
        int j = i;
        while(j < n && a[j] == a[i])
            j++;

        if(j - i == 1) {
            cout << -1 << endl;
            return;
        }

        for(int k = i; k < j - 1; k++)
            p[k] = k + 1;
        p[j - 1] = i;
        i = j;
    }

    for(int x : p)
        cout << x + 1 << ' ';
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