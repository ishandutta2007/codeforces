#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int q;
    unordered_map<string, string> mp;
    cin >> q;
    for (int i=0; i<q; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        bool userExists = false;
        for (auto p : mp)
            if (p.second == s1) {
                userExists = true;
                mp[p.first] = s2;
            }
        if (!userExists)
            mp.insert(make_pair(s1, s2));
    }
    
    cout << mp.size() << endl;
    for (auto p : mp)
        cout << p.first << " " << p.second << endl;
    
    return 0;
}