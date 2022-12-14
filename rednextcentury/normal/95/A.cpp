# include<iostream>
# include<iomanip>
#include <cstdio>
# include <algorithm>
#include <string>
#include <cctype>
using namespace std;
string a[1000];
bool vis[10000];
int len[1000];
bool is(char k)
{
    return ( k >= 'A' && k<='Z');
}
int main()
{
    string s;
    string b="";
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        len[i]=a[i].length();
        for (int x=0;x<len[i];x++)
            a[i][x]=tolower(a[i][x]);
    }
    cin>>s;
    char letter,next;
    cin>>letter;
    if (letter=='a')
        next='b';
    else
        next='a';

    int m=s.length();
    for (int i=0;i<m;i++)
    {
        b+=tolower(s[i]);
    }
    for (int i=0;i<m;i++)
    {
        for (int x=0;x<n;x++)
        {
            if (i+len[x]<=s.length() && b.substr(i,len[x])==a[x])
            {
                for (int j=i;j<i+len[x];j++)
                {
                    vis[j]=1;
                }
            }
        }
    }
    for (int i=0;i<m;i++)
    {
        if (vis[i])
        {
            if (b[i]==letter)
                b[i]=next;
            else
                b[i]=letter;
        }
        if (is(s[i]))
            b[i]=toupper(b[i]);
    }
    cout<<b<<endl;
}