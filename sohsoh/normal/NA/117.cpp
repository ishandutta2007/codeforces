#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a[26] = {0};
    string s1, s2, s;
    cin >> s1 >> s2 >> s;

    for (int i = 0; i < s1.size(); i++) {
        a[s1[i] - 'A']++;
    }

    for (int i = 0; i < s2.size(); i++) {
        a[s2[i] - 'A']++;
    }

    for (int i = 0; i < s.size(); i++) {
        a[s[i] - 'A']--;
    }

    for (int i = 0; i < 26; i++) {
        if (a[i] != 0) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}