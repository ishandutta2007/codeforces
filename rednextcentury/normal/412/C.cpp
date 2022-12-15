# include <iostream>
# include <stdio.h>
# include <cstring>
# include <cstdlib>
# include <algorithm>
# include <map>
# include <iomanip>
# include <string>
# include <ios>
# include <vector>
# include <algorithm>
using namespace std;
int a[100011][27];
int b[100011];
char c[110000];
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int h;
    for (int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        int g=s.length();
        h=g;
        for(int x=0;x<g;x++)
        {
            if (s[x]!='?')
            {
                if (++a[x][(int)s[x]-'a']==1)
                {
                    b[x]++;
                    if (b[x]==1)
                        c[x]=s[x];
                    else
                        c[x]='?';
                }
            }
        }
    }
    for (int i=0;i<h;i++)
    {
        if ((c[i]<'a' || c[i]>'z') && c[i]!='?')
            cout<<'a';
        else
            cout<<c[i];
    }
    cout<<"\n";
}