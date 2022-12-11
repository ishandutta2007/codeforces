#include <iostream>
#include <string>

using namespace std;

string s;
int t;

int main()
{
    cin >> s;
    for (int i = 0; i < s.length() / 2; i++)
    if (s[i] != s[s.length() - i - 1]) {
        cout << "NO\n";
        return 0;
    }
    char ch;
    for (int i = 0; i < s.length(); i++) {
        ch = s[i];
        if (ch == 'U' || ch == 'Y' || ch == 'A' || ch == 'H' || ch == 'X' || ch == 'O' || ch == 'I' || ch == 'M' || ch == 'T' || ch == 'V' || ch == 'W')
            t = t;
        else {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}