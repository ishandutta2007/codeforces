#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int e = 0;
    char last = '2';
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != last) {
            e = 1;
            last = s[i];
        } else {
            e++;
        }

        if (e >= 7) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}