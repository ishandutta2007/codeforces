//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
//using matr

const int INF = 1e9 + 13;
const int N = 1e6 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;

mt19937 rnd(time(0));

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b = a;
    sort(a.begin(), a.end());

    int ans = 1;
    for(int i = 1; i < n; i++) {
//        cout << i << endl;
        int j = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
//    cout << i << ' ' << j << endl;
        if(j == 0 || a[j - 1] != b[i - 1])
            ans++;
    }

    cout << (ans <= k ? "Yes" : "No") << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}