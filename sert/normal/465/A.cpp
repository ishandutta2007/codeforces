#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

string s;
int uk;

int main() {
    ///freopen("a.in", "r", stdin);
    cin >> uk >> s;
    if (s[s.length() - 1] == '1')
        s[s.length() - 1]--;
    for (uk = 0; s[uk] == '1'; uk++);
    cout << uk + 1;
    return 0;
}