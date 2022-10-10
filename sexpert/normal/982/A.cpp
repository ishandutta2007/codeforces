#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    char last = 'a';
    int len = 0;
    string s;
    cin >> s;
    bool flag = true;
    for(int i = 1; i < n - 1; i++)
    {
        char c = s[i];
        if(c == '1')
        {
            if(s[i-1] == '1' || s[i + 1] == '1') flag = false;
        }
        else
        {
            if(s[i-1] == '0' && s[i + 1] == '0') flag = false;
        }
    }
    if(n > 1)
    {
        if(s[0] == s[1] || s[n-1] == s[n - 2]) flag = false;
    }
    else
    {
        if(s[0] == '0') flag = false;
    }
    if(flag) cout << "Yes";
    else cout << "No";
}