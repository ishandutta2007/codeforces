#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    cin >> s;

    int d = 0, a = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A')
            a++;
        else
            d++;
    }

    if (a > d)
        cout << "Anton" << endl;
    else if (a < d)
        cout << "Danik" << endl;
    else
        cout << "Friendship" << endl;
    return 0;
}