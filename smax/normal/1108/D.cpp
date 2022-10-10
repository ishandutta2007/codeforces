#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    int r = 0;
    for (int i=1; i<n-1; i++)
        if (s[i] == s[i-1]) {
            r++;
            if (s[i-1] == 'R' && s[i+1] == 'R' || s[i-1] == 'R' && s[i+1] == 'B' || s[i-1] == 'B' && s[i+1] == 'R' || s[i-1] == 'B' && s[i+1] == 'B')
                s[i] = 'G';
            else if (s[i-1] == 'R' && s[i+1] == 'R' || s[i-1] == 'R' && s[i+1] == 'G' || s[i-1] == 'G' && s[i+1] == 'R' || s[i-1] == 'G' && s[i+1] == 'G')
                s[i] = 'B';
            else
                s[i] = 'R';
        }
    if (n > 1 && s[n-1] == s[n-2]) {
        r++;
        if (s[n-2] == 'R' || s[n-2] == 'B')
            s[n-1] = 'G';
        else
            s[n-1] = 'R';
    }
    
    cout << r << "\n" << s << endl;
    
    return 0;
}