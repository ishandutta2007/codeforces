#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        c = tolower(c);
        if (!(c == 'a' || c == 'o' || c == 'y' || c == 'e' || c == 'u' || c == 'i')) {
            cout << '.' << c;
        }
    }
    return 0;
}