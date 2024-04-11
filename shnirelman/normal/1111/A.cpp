#include <bits/stdc++.h>

using namespace std;

int main(){
    string s, t;
    cin >> s >> t;
    
    if(s.length() != t.length()){
        cout << "No";
        return 0;
    }
    
    for(int i = 0; i < s.length(); i++){
        bool b1 = (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u');
        bool b2 = (t[i] == 'a' || t[i] == 'e' || t[i] == 'i' || t[i] == 'o' || t[i] == 'u');
        
        if(b1 ^ b2){
            cout << "No";
            return 0;
        }
    }
    
    cout << "Yes";
}