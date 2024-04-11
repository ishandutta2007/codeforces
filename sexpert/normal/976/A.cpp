#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, ones = 0, zeros = 0;
    cin >> n;
    string s;
    cin >> s;
    for(char c : s)
    {
        if (c == '0') zeros++;
        else ones++;
    }
    if(ones == 0) cout << s;
    else
    {
        string res = "1";
        while(zeros--) res += "0";
        cout << res;
    }
}