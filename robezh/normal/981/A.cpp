#include <bits/stdc++.h>
using namespace std;

string str;
int res = 0;

bool good(string str){
    for(int i = 0; i < str.length(); i++){
        if(str[i] != str[str.length()-1-i]){
            return true;
        }
    }
    return false;
}


int main() {
    getline(cin, str);
    for(int i = 0; i < str.length()-1; i++){
        for(int j = 1; j <= (str.length()-i); j++){
            string now = str.substr(i,j);
            if(good(now) && now.length() > res) res = now.length();
        }
    }
    cout << res;
}