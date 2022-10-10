#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i = 0 ; i < t; i++)
    {
        int n;
        cin >> n;
        bool flag = true;
        string s;
        cin >> s;
        for(int j = 0; j < n; j++)
        {
            int d = abs(s[j] - s[n - 1 - j]);
            if(d != 0 && d != 2) flag = false;
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
}