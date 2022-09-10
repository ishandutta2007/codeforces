#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s;

int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;

    while(n--)
    {
        cin >> s;

        if(s.size()>10)
        {
            cout << s[0] << s.size()-2 << s[s.size()-1] << '\n';
        }
        else
        {
            cout << s << '\n';
        }
    }


}