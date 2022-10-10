#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d, mx = 0, ct = 0;
    cin >> n >> d;
    for(int i = 0; i < d; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < n; j++) {
            if(s[j] == '0') {
                ct++;
                break;
            }
            if(j == n - 1)
                ct = 0;
        }
        mx = max(mx, ct);
    }
    cout << mx << endl;
}