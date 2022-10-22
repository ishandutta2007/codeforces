#include <bits/stdc++.h>

using namespace std;

bool is_pal(string s) {
    for(int i = 0; i <= s.length() / 2; i++)
        if(s[i] != s[s.length() - i - 1])
            return false;
            
    return true;
}

int main() {
    string s;
    cin >> s;
    
    int n = s.length();
    
    bool fl = false;
    for(int i = 1; i < n / 2; i++)
        if(s[i] != s[i - 1])
            fl = true;
    
    if(!fl) {
        cout << "Impossible";
        return 0;
    }
    
    for(int i = 1; i < n; i++) {
        string t = s.substr(i, s.length() - i) + s.substr(0, i);
        if(is_pal(t) && t != s) {
            cout << 1;
            return 0;
        }
    }
    
    cout << 2;
    /*if(n % 2) {
        string t = s.substr(0, s.length() / 2);
        if(is_pal(t)) {
            fl = false;
            for(int i = 1; i < t.length(); i++)
                if(t[i] != t[i - 1])
                    fl = true;
                        
            if(!fl) {
                cout << "Impossible";
                return 0;
            }
            
            if(t.length() % 2 == 0) {
                
                
                cout << 2;
            } else {
                cout << 2;
            }
        } else {
            cout << 2;
            return 0;
        }
    } else {
        //cout << 1;
        //return 0;
        string t = s.substr(0, s.length() / 2);
        if(is_pal(t)) {
            if(t.length() % 2 == 0) {
                string s1 = t.substr(0, t.length() / 2);
                if(is_pal(s1) && s1.length() % 2 == 1) {
                    cout << 2;
                } else
                    cout << 1;
            } else {
                cout << 2;
            }
        } else {
            cout << 1;
            return 0;
        }
    }*/
}