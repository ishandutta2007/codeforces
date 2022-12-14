# include <iostream>
# include <stdio.h>
# include <cstring>
# include <cstdlib>
# include <algorithm>
# include <map>
# include <iomanip>
# include <string>
# include <ios>
# include <queue>
# include <algorithm>
using namespace std;
bool a[26];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    a[0]=1;
    a[7]=1;
    a[8]=1;
    a[12]=1;
    a[14]=1;
    a[19]=1;
    a[20]=1;
    a[21]=1;
    a[22]=1;
    a[23]=1;
    a[24]=1;
    string s;
    cin>>s;
    int n=s.length();
    for (int i=0;i<n;i++)
    {
        if (a[int(s[i]-'A')]==0 || s[i]!=s[n-i-1])
        {
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
}