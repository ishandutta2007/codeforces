#include <bits/stdc++.h>
using namespace std;
 
int diff(string a, string b) {
    string original = a;
    int ret = 0;
    while (a != b) {
        a = a.substr(1) + a[0];
        ret++;
        if (a == original)
            return -1;
    }
    return ret;
}
 
int main() {
    int n, ret = INT_MAX;
    string s[50];
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> s[i];
    
    for (int i=0; i<n; i++) {
        int acc = 0;
        for (int j=0; j<n; j++) {
            acc += diff(s[j], s[i]);
            if (acc == -1) {
                cout << -1 << endl;
                return 0;
            }
        }
        ret = min(ret, acc);
    }
    
    cout << ret << endl;
    
    return 0;
}