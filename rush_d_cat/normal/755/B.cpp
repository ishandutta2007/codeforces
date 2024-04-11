#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
using namespace std;
int a, b, c, n, m;
map<string, int> mp;
string s;
int main()
{
    cin >> n >> m;a = n;
    for(int i=1;i<=n;i++)
    {
        cin >> s;
        mp[s] = 1;
    }
    for(int i=1;i<=m;i++)
    {
        cin >> s;
        if(mp[s])
        {
            a --;
            b ++;
        } else {
            c ++;
        }
    }
    if(a+(b+1)/2 > c + b - (b+1)/2) cout << "YES";
    else cout << "NO" << endl;
}