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
    int n;
    cin >> n;

    int sum = 0;
    for(int i = 1; i < n / 2; i++) {
        sum += ( 1<< i);
    }

    sum += (1 << n);
    for(int i = n / 2; i < n; i++)
        sum -= (1 << i);

    cout << sum << endl;
//    int n;
//    cin >> n;
//
//    vector<int> a(n);
//    for(int i = 0; i < n; i++) {
//        cin >> a[i];
//    }
}
//
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}