#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        string s;
        cin >> s;
        int n = s.size();
        s = "?" + s + "?";
        for(int i = 1; i <= n; i++){
            if(s[i] == '?'){
                for(int j = 0; j < 3; j++){
                    if(char('a' + j) != s[i - 1] && char('a' + j) != s[i + 1]) s[i] = char('a' + j);
                }
            }
        }
        bool f = true;
        for(int i = 1; i < n; i++) if(s[i] == s[i + 1]){
            cout << -1 << endl;
            f = false;
            break;
        }
        if(f){
            for(int i = 1; i <= n; i++) cout << s[i];
            cout << endl;
        }
    }
}