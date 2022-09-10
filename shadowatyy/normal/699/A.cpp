#include <bits/stdc++.h>
#define inf 2000000000
using namespace std;

int res = inf;

int n;

string s;

int t[200007];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> s;

    s = '#' + s;

    for(int i = 1; i <= n; ++i)
    {
        cin >> t[i];
    }

    for(int i = 1; i < n; ++i)
    {
        if(s[i]=='R' && s[i+1]=='L')
        {
            res = min(res, (t[i+1]-t[i])/2);
        }
    }

    if(res==inf)
    {
        cout << -1;
    }
    else
    {
        cout << res;
    }


}