#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s;
    cin >> s;
    for (int i=1; i<s.length(); i++)
        if (s[i] == s[i-1]) {
            s[i] = max(s[i-1], s[i+1]) + 1;
            if (!isalpha(s[i])) {
                s[i] = min(s[i-1], s[i+1]) - 1;
                if (!isalpha(s[i]))
                    s[i] = 'm';
            }
        }
    cout << s << endl;
    
    return 0;
}