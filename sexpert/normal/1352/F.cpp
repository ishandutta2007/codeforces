#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    string s;
    if(a == 0 && c == 0) {
        for(int i = 0; i <= b; i++)
            s += ('0' + (i % 2));
    }
    if(a > 0 && c == 0) {
        s = '0';
        for(int i = 0; i < a; i++)
            s += '0';
        for(int i = 0; i < b; i++)
            s += ('1' - (i % 2));
    }
    if(a == 0 && c > 0) {
        s = '1';
        for(int i = 0; i < c; i++)
            s += '1';
        for(int i = 0; i < b; i++)
            s += ('0' + (i % 2));
    }
    if(a > 0 && c > 0) {
        s = '0';
        for(int i = 0; i < a; i++)
            s += '0';
        for(int i = 0; i <= c; i++)
            s += '1';
        for(int i = 0; i < b - 1; i++)
            s += ('0' + (i % 2));
    }
    cout << s << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}