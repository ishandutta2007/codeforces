#include <iostream>
#include <map>
using namespace std;
map<char, char> m;
string a, b, c;
int main()
{
    cin>>a>>b>>c;
    for(int i=0; i<a.length(); i++)
    {
        m[a[i]] = b[i];
        m[a[i]+'A'-'a'] = b[i]+'A'-'a';
    }
    for(int i=0; i<c.length(); i++)
    {
        if('0' <= c[i] && c[i] <= '9')
        {
            cout<<c[i];
        }
        else
        {
            cout<<m[c[i]];
        }
    }
}