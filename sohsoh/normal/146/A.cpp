#include <iostream>

using namespace std;

bool isLucky(string n) {
    for (int i = 0; i < n.size(); i++) {
        if (n[i] != '4' && n[i] != '7') {
            return false;
        }
    }

    return true;
}

bool isHalf(string n) {
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n.size() / 2; i++) {
        s1 += n[i] - '0';
    }

    for (int i = n.size() / 2; i < n.size(); i++) {
        s2 += n[i] - '0';
    }

    if (s1 == s2)
        return true;

    return false;
}

int main()
{
    int uu;
    cin >> uu;

    string n;
    cin >> n;

    if (isLucky(n) && isHalf(n)) {
        cout << "YES" << endl;
        return 0;
    }

    cout << "NO" << endl;
    return 0;
}