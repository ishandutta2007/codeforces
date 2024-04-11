#include <bits/stdc++.h>
using namespace std;

string str;

int main() {
    getline(cin, str);

    char c = 'a';
    for(int i = 0; i < str.length(); i++){
        if(str[i] <= c){
            str[i] = c;
            c++;
            if(c > 'z') break;
        }
    }
    if(c > 'z') cout << str;
    else cout << -1;
}