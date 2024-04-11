#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    string s = "";
    cin >> n;
    for (int i=0; i<n; i++) {
        string m;
        cin >> m;
        s += m;
    }
    
    int ret = 1;
    for (int i=1; i<2*n; i++)
        if (s[i] == s[i-1])
            ret++;
    
    cout << ret << endl;
    
    return 0;
}