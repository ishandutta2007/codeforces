#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int m, a[100000];
    string s;
    cin >> s >> m;
    a[0] = s[0] == s[1];
    for (int i=1; i<s.length()-1; i++)
        a[i] = a[i-1] + (s[i] == s[i+1]);
    for (int i=0; i<m; i++) {
        int l, r;
        cin >> l >> r;
        if (l == 1)
            cout << a[r-2] << endl;
        else
            cout << a[r-2] - a[l-2] << endl;
    }
    
    return 0;
}