#include <bits/stdc++.h>
using namespace std;
char s[1200000];
string a, b, c;
int main() {
    gets(s); a = s;
    gets(s); b = s;
    if (a.length() < b.length()) {
        for (int i = a.length(); i < b.length(); i++)
            c += "0";
        a = c + a;
    } else {
        for (int i = b.length(); i < a.length(); i++)
            c += "0";
        b = c + b;
    }
    if (a < b)
        cout << "<";
    else if (a > b)
        cout << ">";
    else
        cout << "=";
}