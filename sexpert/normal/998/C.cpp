#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, x, y, comp = 0;
    char prev = '*';
    string s;
    cin >> n >> x >> y >> s;
    s += '*';
    for(int i = 0; i < s.length(); i++)
    {
        if(prev == '0')
        {
            if(s[i] != '0') comp++;
        }
        prev = s[i];
    }
    //cout << comp << endl;
    if(comp == 0) cout << 0;
    else cout << y + (comp - 1)*min(x, y);
}