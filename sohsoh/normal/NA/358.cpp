#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    char p[3] = {'a', 'b', 'c'};

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        bool b = true;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '?') {
                for (int j = 0; j < 3; j++) {
                    if ((i == 0 || p[j] != s[i - 1]) && (i == s.size() - 1 || s[i + 1] != p[j])) {
                        s[i] = p[j];
                        break;
                    }
                }
            }

            if (i != 0 && s[i] == s[i - 1]) {
                b = false;
                break;
            }
        }

        if (!b) {
            cout << -1 << endl;
            continue;
        }
        cout << s << endl;
    }
    return 0;
}