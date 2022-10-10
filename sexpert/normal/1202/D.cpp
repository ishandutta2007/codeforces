#include <bits/stdc++.h>
using namespace std;

const int uwu = 299*150;

void solve() {
    int n;
    cin >> n;
    int a = n/uwu, b = n%uwu;
    string s = "133";
    while(b--)
        s += '7';
    if(a) {
        for(int i = 0; i < 298; i++)
            s += '3';
        while(a--)
            s += '7';
    }
    assert(s.size() <= 100000);
    cout << s << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--)
        solve();
}