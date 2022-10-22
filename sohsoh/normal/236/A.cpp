#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    bool a[26] = {0};

    int n = 0;
    for (int i = 0; i < s.size(); i++) {
        if (!a[s[i] - 'a']) {
            n++;
            a[s[i] - 'a'] = true;
        }
    }

//    cout << n << endl;

    if (n % 2 == 0) {
        cout << "CHAT WITH HER!" << endl;
    } else {
        cout << "IGNORE HIM!" << endl;
    }
    return 0;
}