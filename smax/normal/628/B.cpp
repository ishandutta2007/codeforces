#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long ret = 0;
    string s;
    cin >> s;
    for (int i=s.length()-1; i>0; i--) {
        if ((s[i] - '0') % 4 == 0)
            ret++;
        if ((10 * (s[i-1] - '0') + (s[i] - '0')) % 4 == 0)
            ret += i;
    }
    if ((s[0] - '0') % 4 == 0)
        ret++;
    
    cout << ret << "\n";
    
    return 0;
}