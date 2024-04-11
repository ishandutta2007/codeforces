#include <bits/stdc++.h>
using namespace std;

string str;

int main(){
    getline(cin, str);
    cout << str;
    for(int i = str.length()-1; i >= 0; i--) cout << str[i];
}