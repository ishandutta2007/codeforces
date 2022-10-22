#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] >= 'a') {
            cout << s << endl;
            return 0;
        }
    }

    if (s[0] >= 'a')
        s[0] = toupper(s[0]);
    else
        s[0] = tolower(s[0]);

    for (int i = 1; i < s.size(); i++)
        s[i] = tolower(s[i]);

    cout << s << endl;
    return 0;
}