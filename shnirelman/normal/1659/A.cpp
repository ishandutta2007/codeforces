#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n, r, b;
    cin >> n >> r >> b;

    int x = r / (b + 1);
    string s = "";
    for(int i = 0; i < r % (b + 1); i++) {
        for(int j = 0; j <= x; j++)
            s += 'R';
        s += 'B';
    }

    for(int i = r % (b + 1); i < b + 1; i++) {
        for(int j = 0; j < x; j++)
            s += 'R';
        if(i < b)
            s += 'B';
    }

    cout << s << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}