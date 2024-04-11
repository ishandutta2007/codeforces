#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    unordered_map<char, int> bleh;
    for (char c : s3) {
        if (bleh.find(c) == bleh.end())
            bleh.insert(make_pair(c, 1));
        else
            bleh[c]++;
    }
    
    bool yes = true;
    for (char c : s1) {
        if (bleh.find(c) == bleh.end()) {
            yes = false;
            break;
        } else {
            bleh[c]--;
            if (bleh[c] == 0)
                bleh.erase(c);
        }
    }
    if (yes)
        for (char c : s2) {
            if (bleh.find(c) == bleh.end()) {
                yes = false;
                break;
            } else {
                bleh[c]--;
                if (bleh[c] == 0)
                    bleh.erase(c);
            }
        }
    
    if (!yes || bleh.size() != 0)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    
    return 0;
}