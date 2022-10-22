#include <iostream>
#include <string>

using namespace std;

int main()
{
    bool g1, g2, transf = true;
    string s, t;
    cin >> s >> t;
    if (s.length() != t.length())
        cout << "No" << endl;
    else
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                g1 = true;
            else g1 = false;
            if (t[i] == 'a' || t[i] == 'e' || t[i] == 'i' || t[i] == 'o' || t[i] == 'u')
                g2 = true;
            else g2 = false;
            if (g1 != g2)
            {
                transf = false;
            }
        }
        if (transf) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}