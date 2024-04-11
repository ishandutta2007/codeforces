#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    int n, m = 0;
    string s, t;
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        if(m % 2 && s[i] == t[m - 1]) continue;
        t += s[i];
        m++;
    }
    if(m % 2) {
        m--;
        t = t.substr(0, m);
    }
    cout << n - m << '\n' << t << '\n';
}