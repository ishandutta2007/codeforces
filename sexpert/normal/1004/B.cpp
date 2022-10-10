#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, l, r;
    cin >> n >> m;
    string s = "";
    for(int i = 0; i < m; i++) cin >> l >> r;
    for(int i = 0; i < n; i++)
    {
        if(i%2) s+='0';
        else s+='1';
    }
    cout << s;
}