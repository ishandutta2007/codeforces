#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    bool correct = true;
    for (int i=0; i<s.length(); i++)
        if (s[i] != t[s.length()-i-1])
            correct = false;
    if (correct)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}