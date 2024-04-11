#include<bits/stdc++.h>

using namespace std;

int i,n,ans1,ans2;
string s,t;

int main()
{
    getline(cin,s);
    getline(cin,t);
    n=s.length();
    for (i=0; i<n; i++)
    {
        if ((s[i]=='4')&(t[i]=='7'))
        {
            ans1++;
        }
        if ((s[i]=='7')&(t[i]=='4'))
        {
            ans2++;
        }
    }
    cout<<max(ans1,ans2)<<endl;
}