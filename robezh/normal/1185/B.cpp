#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int n, m;
string s, t;

bool solve() {
    cin >> s >> t;
    n = s.length(), m = t.length();
    int i = 0, j = 0;
    while(i < n && j < m) {
        int ir = i, jr = j;
        while(ir < n && s[ir] == s[i]) ir++;
        while(jr < m && t[jr] == t[j]) jr++;
        if(s[i] != t[j] || (ir - i) > (jr - j)) return false;
        i = ir, j = jr;
    }
    return i == n && j == m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while(T--) {
        cout << (solve() ? "YES" : "NO") << "\n";
    }
}