#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s, t;
    cin >> s >> t;
    if(s.length() != t.length()) {
        cout << "No\n";
        return 0;
    }
    set<char> vow = {'a', 'e', 'i', 'o', 'u'};
    for(int i = 0; i < s.length(); i++) {
        if((vow.count(s[i]) && vow.count(t[i])) || (!vow.count(s[i]) && !vow.count(t[i])))
            continue;
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
}