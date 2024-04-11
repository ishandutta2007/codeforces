#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int p;
string s[3], k;
char ch;

int main() {
    ///freopen("a.in", "r", stdin);
    cin >> ch;
    if (ch == 'R') p = -1;
    else p = 1;
    s[0] = "qwertyuiop";
    s[1] = "asdfghjkl;";
    s[2] = "zxcvbnm,./";
    cin >> k;
    for (int i = 0; i < k.length(); i++)
        for (int j = 0; j < 3; j++)
            for (int ii = 0; ii < s[j].length(); ii++)
                if (s[j][ii] == k[i])
                    cout << s[j][ii + p];
    return 0;
}