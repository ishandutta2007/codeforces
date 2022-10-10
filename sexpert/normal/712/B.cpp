#include <bits/stdc++.h>
using namespace std;

int x, y;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    if(n % 2) {
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < n; i++) {
        if(s[i] == 'L')
            x--;
        if(s[i] == 'R')
            x++;
        if(s[i] == 'U')
            y++;
        if(s[i] == 'D')
            y--;
    }
    if(abs(x) % 2 == 0) {
        cout << abs(x)/2 + abs(y)/2 << endl;
        return 0;
    }
    x = abs(x), y = abs(y);
    cout << x/2 + y/2 + 1 << endl;
}