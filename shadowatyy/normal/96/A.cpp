#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s;

int c = 1;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> s;

    s = '#' + s;

    for(int i = 1; i < s.size(); i++)
    {
        if(s[i]==s[i-1])
        {
            c++;
        }
        else
        {
            c = 1;
        }

        if(c==7)
        {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}