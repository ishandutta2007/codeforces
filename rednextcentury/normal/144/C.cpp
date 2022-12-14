# include <iostream>
# include <string>
# include <map>
# include <stdio.h>
# include <cmath>
# include <cstdio>
# include <queue>
# include <algorithm>
# include <stack>
# include <cstring>
# include <iomanip>
# include<cstdlib>
using namespace std;
int now[26];
int need[26];
int main()
{
    string s,p;
    cin>>s>>p;
    int m=p.length();
    for (int i=0;i<m;i++)
    {
        need[p[i]-'a']++;
    }
    int ans=0;
    int n=s.length();
    int j=0;
    for (int i=0;i<n;i++)
    {
        if (i-j+1<m)
        {
            if (s[i]!='?')
                now[s[i]-'a']++;
        }
        else
        {
            if (s[i]!='?')
                now[s[i]-'a']++;
            bool g=1;
            for (int x=0;x<26;x++)
            {
                if (now[x]>need[x])
                    g=0;
            }
            if (g==1)
                ans++;
            j++;
            if ('?'!=s[j-1])
            now[s[j-1]-'a']--;
        }
    }
    cout<<ans<<endl;
}