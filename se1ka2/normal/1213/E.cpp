#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "YES" << endl;
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    char c[3];
    if(s[0] == s[1]){
        if(t[1] - t[0] == 1 || t[1] - t[0] == -2) for(int i = 0; i < n; i++) cout << "acb";
        else for(int i = 0; i < n; i++) cout << "abc";
    }
    else if(t[0] == t[1]){
        if(s[1] - s[0] == 1 || s[1] - s[0] == -2) for(int i = 0; i < n; i++) cout << "acb";
        else for(int i = 0; i < n; i++) cout << "abc";
    }
    else if(s[0] == t[0]){
        c[0] = s[0];
        if(c[0] == 'a'){
            c[1] = 'b';
            c[2] = 'c';
        }
        if(c[0] == 'b'){
            c[1] = 'a';
            c[2] = 'c';
        }
        if(c[0] == 'c'){
            c[1] = 'a';
            c[2] = 'b';
        }
        for(int i = 0; i < 3; i++) for(int j = 0; j < n; j++) cout << c[(i + 1) % 3];
    }
    else if(s[0] == t[1] && t[0] == s[1]){
        c[0] = s[0];
        c[1] = s[1];
        if(c[0] != 'a' && c[1] != 'a') c[2] = 'a';
        if(c[0] != 'b' && c[1] != 'b') c[2] = 'b';
        if(c[0] != 'c' && c[1] != 'c') c[2] = 'c';
        for(int j = 0; j < n; j++) cout << c[0];
        for(int j = 0; j < n; j++) cout << c[2];
        for(int j = 0; j < n; j++) cout << c[1];
    }
    else{
        c[0] = s[0];
        c[1] = s[1];
        if(c[0] != 'a' && c[1] != 'a') c[2] = 'a';
        if(c[0] != 'b' && c[1] != 'b') c[2] = 'b';
        if(c[0] != 'c' && c[1] != 'c') c[2] = 'c';
        for(int j = 0; j < n; j++) cout << c[1];
        for(int j = 0; j < n; j++) cout << c[0];
        for(int j = 0; j < n; j++) cout << c[2];
    }
}