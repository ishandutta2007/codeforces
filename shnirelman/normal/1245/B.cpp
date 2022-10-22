#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;
using li = long long;

void solve() {
    int n;
    cin >> n;

    int a, b, c;
    cin >> a>> b >> c;

    string s;
    cin >> s;

    int d = 0;
    vector<char> w(n, '.');
    for(int i = 0; i < n; i++) {
        char s1 = s[i];
        if(s1 == 'R') {
            if(b > 0) {
                b--;
                d++;
                w[i] = 'P';
            }
        } else if(s1 == 'P') {
            if(c > 0) {
                c--;
                d++;
                w[i] = 'S';
            }
        } else {
            if(a > 0) {
                a--;
                d++;
                w[i] = 'R';
            }
        }
    }

    if(d >= (n + 1) / 2) {
        cout << "YES" << endl;
        for(int i = 0; i < n; i++)
            if(w[i] == '.') {
                if(a > 0) {
                    w[i] = 'R';
                    a--;
                } else if(b > 0) {
                    w[i] = 'P';
                    b--;
                } else {
                    w[i] = 'S';
                    c--;
                }
            }

        for(auto s1 : w)
            cout << s1;
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}