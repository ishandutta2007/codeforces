#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    string s,s1="hello";
    int o=0;
    cin>>s;
    for (int i=0;i<s.size();i++)
    {
        if (o==5) break;
        if (s[i]==s1[o]) o++;
    }
    if (o==5) cout<<"YES"; else cout<<"NO";
    return 0;
}