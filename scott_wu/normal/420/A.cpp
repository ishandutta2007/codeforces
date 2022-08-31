#include <iostream>
#include <string>

using namespace std;

string g = "AHIMOTUVWXY";

bool in (char ch)
{
for (int i = 0; i < g.length(); i++)
if (ch == g[i])
return true;
return false;
}

int main()
{
    string s;
    cin >> s;
    int N = s.length();
    
    bool good = true;
    for (int i = 0; i < N; i++)
    {
        if (s[i] != s[N-1-i])
            good = false;
        if (!in (s[i]))
            good = false;
    }
    cout << ((good) ? "YES" : "NO") << "\n";
    return 0;
    }