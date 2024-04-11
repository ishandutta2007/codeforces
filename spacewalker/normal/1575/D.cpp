#include <bits/stdc++.h>

using namespace std;

int main() { 
    string s;
    cin>>s;
    int tot = 0;
    for (int i = 0; i < 99999999; i+= 25) {
        string istr = to_string(i);
        if (istr.size() != s.size()) continue;
        char X = '?';
        bool able = true;
        for (int j = 0; j<istr.size();j++) {
            if (s[j] == 'X') {
                if (X == '?' || X == istr[j]) {
                    X = istr[j];
                } else {
                    able = false;
                }
            } else if (s[j] != '_') {
                if (s[j] != istr[j]) {
                    able = false;
                }
            } else{}
        }
        tot += able;
    }cout<<tot;

}