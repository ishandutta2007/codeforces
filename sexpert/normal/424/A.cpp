#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ctdown = 0;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'x')
            ctdown++;
    }
    int res = abs(ctdown - n/2);
    for(int i = 0; i < n; i++) {
        if(s[i] == 'x' && ctdown > n/2) {
            s[i] = 'X';
            ctdown--;
            continue;
        }
        if(s[i] == 'X' && ctdown < n/2) {
            s[i] = 'x';
            ctdown++;
            continue;
        }
    }
    cout << res << endl << s << endl;
}