#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int anspos = -1;
    for(int i = 0; i < s.length() - 1; i++)
    {
        if(s[i] > s[i + 1])
        {
            anspos = i;
            break;
        }
    }
    string ans = "";
    if(anspos == -1)
        ans = s.substr(0, s.length() - 1);
    else
    {
        for(int i = 0; i < s.length(); i++)
        {
            if(i != anspos)
                ans += s[i];
        }
    }
    cout << ans << endl;
}