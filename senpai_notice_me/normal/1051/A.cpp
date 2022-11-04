#include <bits/stdc++.h>

using namespace std;

string s;
int digit, upper, lower;
int d, u, l;

int main() {
    int T; cin >> T;
    while (T--) {
        digit = upper = lower = 0;
        d = u = l = -1;
        
        cin >> s;
        
        for (int i = 0; i < (int)s.length(); ++i) {
            if (isupper(s[i])) upper += 1, u = i;
            else if (islower(s[i])) lower += 1, l = i;
            else if (isdigit(s[i])) digit += 1, d = i;
        }
        
        if (!lower && !digit) {
            s[0] = 'a';
            s[1] = '1';
        } else if (!upper && !digit) {
            s[0] = 'A';
            s[1] = '1';
        } else if (!lower && !upper) {
            s[0] = 'a';
            s[1] = 'A';
        } else if (!lower) {
            if (upper > 1) s[u] = 'a';
            else s[d] = 'a';
        } else if (!upper) {
            if (lower > 1) s[l] = 'A';
            else s[d] = 'A';
        } else if (!digit) {
            if (lower > 1) s[l] = '1';
            else s[u] = '1';
        }
        
        cout << s << endl;
    }
    
    return 0;
}