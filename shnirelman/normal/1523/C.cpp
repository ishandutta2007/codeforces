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
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

//    cout << 1 << endl;
    vector<int> b;//(1, 1);
    for(int i = 0; i < n; i++) {
        if(a[i] == 1) {
            for(int j = 0; j < b.size(); j++)
                cout << b[j] << '.';
            cout << a[i] << endl;
            b.push_back(a[i]);
        } else {
            while(a[i] != b.back() + 1)
                b.pop_back();
            for(int j = 0; j < b.size() - 1; j++)
                cout << b[j] << '.';
            cout << a[i] << endl;
            b.back()++;
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}