#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    string s;
    cin >> s;
    string res = "";

    for (int i = (s.length() - 1) / 2; i >= 0; i--)
    {
        res += s[i];
        if (s.length() % 2 == 1)
        {
            if (i) res += s[s.length() - i];
        }
        else
            res += s[s.length() - 1 - i];
    }
    cout << res << "\n";
}