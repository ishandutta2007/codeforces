# include <iostream>
# include <stdio.h>
# include <cstring>
# include <cstdlib>
# include <algorithm>
# include <cmath>
# include <iomanip>
# include <queue>
# include <ios>
# include <vector>
# include <string>
using namespace std;
int a[1000];
int main()
{
    int n;cin>>n;
    string s;
    cin>>s;
    char last;
    bool sd=0;
    int loc=0;
    int ans=0;
    for (int i=0;i<s.length();i++)
    {
        if (sd==0 && s[i]=='R')
        {
            ans+=i;
            loc=i;
            sd=1;
            last='R';
        }
        else if (sd==0 && s[i]=='L')
        {
            last='L';
            loc=i;
            sd=1;
        }
        if (sd==1 && last=='L' &&s[i]=='R')
            ans+=i-loc-1;
        if (sd==1 && last=='R' && s[i]=='L' && (i-loc)%2==0)
            ans++;
        if (s[i]=='L')
        {
            last='L';
            loc=i;
        }
        else if (s[i]=='R')
        {
            last='R';
            loc=i;
        }
    }
    if (sd==1 && last=='L')
        ans+=s.length()-1-loc;
    if (sd==0)
        ans=s.length();
    cout<<ans<<endl;
}