#include <bits/stdc++.h>
using namespace std;

string mask;

bool check(int n) {
    string s = to_string(n), r = "";
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '4' || s[i] == '7')
            r += s[i];
    }
    return r == mask;
}

int main() {
    int a;
    cin >> a >> mask;
    for(int i = a + 1;;i++) {
        if(check(i)) {
            cout << i << endl;
            return 0;
        }
    }
}