#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int ct = 0;
    for(int i = 0; i < s.length(); i++)
        if(s[i] == '8') ct++;
    cout << min(ct, n/11) << endl;
}