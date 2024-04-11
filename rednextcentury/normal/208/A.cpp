# include <iostream>
# include <map>
# include <string>
# include <algorithm>
# include <queue>
# include <cmath>
using namespace std;
int main()
{
    string s;
    cin>>s;
    string ans="";
    for (int i=0;i<s.length();i++)
    {
        if (s[i]=='W' && s[i+1]=='U' && s[i+2]=='B')
        {
            if (i>0)
                ans+=" ";
            i+=2;
            continue;
        }
        else
            ans+=s[i];
    }
    cout<<ans<<endl;
}