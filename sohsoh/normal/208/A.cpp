#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    s += "  ";

    int last = 2;
    bool ls = true;
    for (int i = 0; i < s.size() - 2; i++) {
        if (!(s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B')) {
            ls = false;
            cout << s[i];
        } else {
            if (!ls) {
                cout << " ";
                ls = true;
            }

            if (i == s.size() - 3) {
                last = 0;
            } else if (i == s.size() - 4) {
                last = 1;
            }

            i += 2;
        }
    }

    if (last == 2) {
        cout << s[s.size() - 2] << s[s.size() - 1] << endl;
    } else if (last == 1) {
        cout << s[s.size() - 1] << endl;
    }
    return 0;
}