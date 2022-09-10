#include <bits/stdc++.h>
using namespace std;

int n;

string s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> s;

    n = s.size();

    for(int i = n-1; i >= 0; i--)
    {
        s.push_back(s[i]);
    }

    cout << s;
}