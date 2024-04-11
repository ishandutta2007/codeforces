#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int sim_s(string s) {
    int r = 0;
    for (int i = 0; i < s.size(); i++) {
        r += s[i] - '0';
    }

    return r;
}

string r0(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            s.erase(s.begin() + i);
            return s;
        }
    }

    return "NO";
}

bool contain_even(string s) {
    for (int i = 0; i < s.size(); i++) {
        int x = s[i] - '0';
        if (x % 2 == 0)
            return true;
    }

    return false;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int x = sim_s(s);
        s = r0(s);
        bool b = contain_even(s);

        if (s != "NO" && b && x % 3 == 0) {
            cout << "red" << endl;
        } else {
            cout << "cyan" << endl;
        }
    }
    return 0;
}