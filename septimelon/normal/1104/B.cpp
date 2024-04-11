#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1;
    cin >> s1;
    bool first, changed;
    first = false;
    changed = true;
    while (changed)
    {
        changed = false;
        for (int i = s1.length()-1; i > 0; i--)
        {
            if (s1[i-1] == s1[i])
            {
                if (first) first = false;
                else first = true;
                changed = true;
                s1.erase(i-1, 2);
            }
        }
    }
    if (first) cout << "Yes";
    else cout << "No";
    return 0;
}