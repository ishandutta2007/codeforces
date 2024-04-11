#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int upper[100000], lower[100000];
    string s;
    cin >> s;
    upper[0] = isupper(s[0]) ? 1 : 0;
    lower[0] = islower(s[0]) ? 1 : 0;
    for (int i=1; i<s.length(); i++) {
        if (isupper(s[i])) {
            upper[i] = upper[i-1] + 1;
            lower[i] = lower[i-1];
        } else {
            upper[i] = upper[i-1];
            lower[i] = lower[i-1] + 1;
        }
    }
    
    int ret = upper[s.length()-1];
    for (int i=0; i<s.length(); i++)
        ret = min(ret, lower[i] + upper[s.length()-1] - upper[i]);
    cout << ret << endl;
    
    return 0;
}