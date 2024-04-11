#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;
    string p;
    int num=0;
    for (int i=0;i<s.length();i++)
    {
        if (s[i]==t[i])
            p+='0';
        else if (num%2==0)
            p+=s[i],num++;
        else
            p+=t[i],num++;
    }
    if (num%2==0)
        cout<<p<<endl;
    else
        cout<<"impossible"<<endl;
}