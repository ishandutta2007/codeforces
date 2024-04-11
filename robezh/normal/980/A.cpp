#include <bits/stdc++.h>
using namespace std;

string str;

int main() {
    cin >> str;
    int a = 0, b = 0;
    for(char c : str){
        if(c == '-') b++;
        else a++;
    }
    if(a == 0 || b % a == 0) cout << "YES";
    else cout << "NO";
}