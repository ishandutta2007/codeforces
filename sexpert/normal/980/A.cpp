#include <bits/stdc++.h>
using namespace std;

int main()
{
    int p = 0, l = 0;
    string s;
    cin >> s;
    for(char c : s)
    {
        if(c == 'o') p++;
        else l++;
    }
    if(p == 0) cout << "YES";
    else
    {
        if(l % p) cout << "NO";
        else cout << "YES";
    }
}