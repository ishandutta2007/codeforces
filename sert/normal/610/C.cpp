#include <bits/stdc++.h>
using namespace std;

string rev(string s) {
    for (int i = 0; i < s.length(); i++)
        s[i] = (s[i] == '+' ? '*' : '+');
    return s;
}
vector <string> s;
int main() {
    s.push_back("*");
    s.push_back("+");
    int n;
    cin >> n;
    for (int i = 0; i < (2 << n) - 2; i++) {
        s.push_back(s[i] + s[i]);
        s.push_back(s[i] + rev(s[i]));
    }
    for (int i = 0; i < (1 << n); i++) {
        cout << s.back() << "\n";
        s.pop_back();
    }
    return 0;
}