#include <iostream>

using namespace std;

int main()
{
    int a[26] = {0};

    int n;
    string s;
    cin >> n >> s;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        if (c > 'Z')
            a[c - 'a']++;
        else
            a[c - 'A']++;
    }

    for (int i = 0; i < 26; i++) {
        if (a[i] <= 0) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}