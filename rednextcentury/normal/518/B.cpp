# include <iostream>
# include<algorithm>
#include <stdio.h>
using namespace std;
int a[100000];
bool vis[1000000];
int main()
{
    string s,t;
    cin>>s>>t;
    int yay=0;
    int whoops=0;
    int n=s.length();
    int m=t.length();
    for (int i=0;i<m;i++)
    {
        a[(int)t[i]-'A']++;
    }
    for (int i=0;i<n;i++)
    {
            if (a[(int)s[i]-'A']>0)
            {
                yay++;
                a[(int)s[i]-'A']--;
                vis[i]=1;
            }
    }
    for (int i=0;i<n;i++)
    {
        if (vis[i])
            continue;
        if (s[i]==tolower(s[i]))
        {
            if (a[toupper(s[i])-'A']>0)
            {
                whoops++;
                a[toupper(s[i])-'A']--;
            }
        }
        else if (s[i]==toupper(s[i]))
        {
            if (a[tolower(s[i])-'A']>0)
            {
                whoops++;
                a[tolower(s[i])-'A']--;
            }
        }
    }
    cout<<yay<<" "<<whoops<<endl;
}