#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        int n;
        cin >> n >> s;
        bool good = false;
        for(int i = 0; i < n; i++) {
            if(s[i] == '8' && i + 10 < n)
                good = true;
        }
        if(good)
            cout << "YES\n";
        else
            cout << "NO\n";
    }    
}