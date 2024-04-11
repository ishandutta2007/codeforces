#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 200000 + 13;
const int M = 1e9 + 7;
const int B = 600;

void solve() {
    int s;
    cin >> s;

    int cur = 0;
    for(int i = 0; ; i++) {
        cur += i * 2 + 1;
        if(cur >= s) {
            cout << i + 1 << '\n';
            return;
        }

    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}