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

int a[N];
int p[N], s[N];

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

//    bool fl = false;
//
//    for(int i = 0; i < n - 1; i++) {
//        if(a[i] > a[i + 1]) {
//            fl = true;
//        }
//
//    }
//
//    if(!fl) {
//        cout << "NO" << endl;
//        return;
//    }

    p[0] = 0;
    for(int i = 1; i < n; i++)
        if(a[i] < a[p[i - 1]])
            p[i] = i;
        else
            p[i] = p[i - 1];

    s[n - 1] = n - 1;
    for(int i = n - 2; i >= 0; i--)
        if(a[i] < a[s[i + 1]])
            s[i] = i;
        else
            s[i] = s[i + 1];

    for(int i = 1; i < n - 1; i++)
        if(a[p[i - 1]] < a[i] && a[i] > a[s[i + 1]]) {
            cout << "YES" << endl;
            cout << p[i - 1] + 1 << ' ' << i + 1 << ' ' << s[i + 1] + 1 << endl;
            return;
        }

    cout << "NO" << endl;
}

int main() {
    int t = 1;
    cin >> t;

    while(t--)
        solve();
}