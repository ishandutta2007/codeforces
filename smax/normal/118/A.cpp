#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s, ret = "";
    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'y'};
    cin >> s;
    
    for (int i=0; i<s.length(); i++)
        if (find(vowels, vowels+6, tolower(s[i])) == end(vowels)) {
            ret += '.';
            ret += tolower(s[i]);
        }
    cout << ret << endl;
    
    return 0;
}