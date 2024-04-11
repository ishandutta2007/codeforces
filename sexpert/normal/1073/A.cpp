#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    for(int i = 0; i < n - 1; i++)
    {
        if(s[i] != s[i + 1])
        {
            string t = "";
            t += s[i];
            t += s[i + 1];
            cout << "YES\n" << t << "\n";
            return 0;
        }
    }
    cout << "NO\n";
}