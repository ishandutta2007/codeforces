#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int up = 0, low = 0;
    for (char c : s)
        isupper(c) ? up++ : low++;
    if (up > low)
        transform(s.begin(), s.end(), s.begin(), ::toupper);
    else
        transform(s.begin(), s.end(), s.begin(), ::tolower);
    
    cout << s << endl;
    
    return 0;
}