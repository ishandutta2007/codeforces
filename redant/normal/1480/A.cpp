#include <iostream>

using namespace std;

int main(){
    int t; cin >> t;
    while (t--) {
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); i++) {
            if (i&1) {
                if (s[i] == 'z') s[i] = 'y';
                else s[i] = 'z';
            } else {
                if (s[i] == 'a') s[i] = 'b';
                else s[i] = 'a';
            }
        }
        cout << s << "\n";
    }

    return 0;
}