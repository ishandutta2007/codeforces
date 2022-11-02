#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < s.length(); i ++) {
        if('0' <= s[i] && s[i] <= '9') {
            if(s[i]-'0'&1) ans ++;
        }
        else {
            if(s[i] == 'a') ans ++;
            else if(s[i] == 'e') ans ++;
            else if(s[i] == 'i') ans ++;
            else if(s[i] == 'o') ans ++;
            else if(s[i] == 'u') ans ++;
        }
    }
    cout << ans << endl;
}