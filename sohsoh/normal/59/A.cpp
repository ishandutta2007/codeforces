#include <iostream>

using namespace std;

char convert(char c, bool tu) {
    if (tu && c > 'Z')
        c -= 'a' - 'A';
    if (!tu && c < 'a')
        c += 'a' - 'A';

    return c;
}

int main()
{
    string s;
    cin >> s;

    int l = 0, u = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] < 'a')
            u++;
        else
            l++;
    }

    bool tu = u > l;
    for (int i = 0; i < s.size(); i++) {
        s[i] = convert(s[i], tu);
    }

    cout << s << endl;

    return 0;
}