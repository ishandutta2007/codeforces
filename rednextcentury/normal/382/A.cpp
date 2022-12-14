# include <iostream>
# include <string>
# include <algorithm>
# include <cmath>
# include <queue>
# include <stack>
# include <map>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int left=0,right=0;
    bool p=0;
    string l="";
    string r="";
    for (int i=0;i<s.length();i++)
    {
        if (s[i]=='|')
        {
            p=1;
            continue;
        }
        if (p==0)
        {
            left++;
            l+=s[i];
        }
        else
        {
            right++;
            r+=s[i];
        }
    }
    string b;
    cin>>b;
    for (int i=0;i<b.length();i++)
    {
        if (left<right)
        {
            l+=b[i];
            left++;
        }
        else
        {
            r+=b[i];
            right++;
        }
    }
    if (left==right)
        cout<<l<<"|"<<r<<endl;
    else
        cout<<"Impossible"<<endl;
}