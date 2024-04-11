#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s;
    cin >> s;
    int x;
    cin >> x;
    if(s == "ABC") {
        cout << ((x < 2000) ? "YES" : "NO") << '\n';
    }
    if(s == "ARC") {
        cout << ((x < 2800) ? "YES" : "NO") << '\n';
    }
    if(s == "AGC") {
        cout << ((x >= 1200) ? "YES" : "NO") << '\n';
    }
}