#include <bits/stdc++.h>

using namespace std;

int main() {
    string keys1, keys2, in;
    char x;
    map<char, char> keyboard;
    
    cin >> keys1 >> keys2;
    for(int i = 0; i < 26; i++){
        keyboard[keys1[i]] = keys2[i];
    }
    cin >> in;
    for (int i = 0; i < in.length(); i++) {
        x = in[i]; 
        
        if(x-'a' > -1 && x - 'a' < 26) {
            cout << keyboard[x];
        } else if(x-'A' > -1 && x - 'A' < 26) {
            cout << char(keyboard[x-'A'+'a'] + 'A' - 'a');
        } else{
            cout << in[i];
        }
    }
    
}