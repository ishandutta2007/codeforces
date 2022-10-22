#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;

        reverse(s.begin(), s.end());

        if (s.size() > 3 && ((s[0] == 'u' && s[1] == 's' && s[2] == 'e' && s[3] == 'd') ||
                (s[0] == 'u' && s[1] == 's' && s[2] == 'a' && s[3] == 'm'))) {
                cout << "JAPANESE" << endl;
        } else if (s.size() > 1 && (s[0] == 'o' && s[1] == 'p')) {
            cout << "FILIPINO" << endl;
        } else {
            cout << "KOREAN" << endl;
        }
    }

    return 0;
}