#include <iostream>
#include <string>

using namespace std;
string s;

int main()
{
    cin >> s;
    int N = s.length();
    bool b = false;
    for (int i = 0; i < N - 2; i++)
    {
        if (s[i] * (int) s[i+1] * s[i+2] == 'A' * (int) 'B' * 'C')
            b = true;
    }
    if (b) cout << "YES\n";
    else cout << "NO\n";
}