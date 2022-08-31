#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;

string s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> s;

    bool b = false;
    for (int i = 0; i < s.length(); i++)
        if (s[i] != s[1])
            b = true;
    bool pal = true;
    for (int i = 0; i < s.length(); i++)
        if (s[i] != s[s.length()-1-i])
            pal = false;

    if (!pal)
        cout << s.length() << "\n";
    else if (b)
        cout << s.length() - 1 << "\n";
    else
        cout << "0\n";
}