#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    unordered_map<string, int> m;
    cin >> n;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        if (m.find(s) == m.end()) {
            m.insert(make_pair(s, 1));
            cout << "OK" << endl;
        } else
            cout << s << m[s]++ << endl;
    }
    
    return 0;
}