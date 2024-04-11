#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    
    sort(s.begin(), s.end());
    
    bool fl = true;
    for(int i = 0; i < s.length(); i++)
        fl &= (s[i] == s[s.length() - i - 1]);
        
    cout << (fl ? "-1" : s) << endl;
      
    string t = s;
    /*int j = 0;
    for(int i = 0; i < a.size(); i++) {
        if(a[i] % 2) {
            cout << -1 << endl;
            return;
        } else {
            for(int l = 0; l * 2 < a[i]; l++) {
                t[j] = t[s.length() - 1 - j] = i;
                j++;
            }
        }
        
    }*/
    
    //cout << t << endl;
}

int main() {
    int t;
    cin >> t;
    
    while(t--)
        solve();
}