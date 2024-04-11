#include <bits/stdc++.h>
using namespace std;

string str;

char y[5] = {'a','e','i','o','u'};
char no[5] = {'1','3','5','7','9'};

bool check(char c){
    if(c <= 'z' && c >= 'a')
        for(int i = 0; i < 5; i++){
            if(c == y[i]) return true;
        }
    else{
        for(int i = 0; i < 5; i++){
            if(c == no[i]) return true;
        }
    }
    return false;
}

int main() {
    int cnt = 0;
    getline(cin, str);
    for(int i = 0; i < str.length(); i++){
        if(check(str[i])) cnt ++;
    }
    cout << cnt;
}