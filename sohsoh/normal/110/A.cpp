#include <iostream>

using namespace std;

bool is_lucky(int n) {
    while (n > 0) {
        if (!(n % 10 == 7 || n % 10 == 4)) {
            return false;
        }

        n /= 10;
    }

    return true;
}

int main()
{
    string s;
    cin >> s;

    int n = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '4' || s[i] == '7')
            n++;
    }

    if (n != 0 && is_lucky(n)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}