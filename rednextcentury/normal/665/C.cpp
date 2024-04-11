#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
s+="a";
    int n=s.length();
    for (int i=1;i<n-1;i++)
    {   if (s[i]==s[i-1])
{
     if (s[i]!='a' && s[i+1]!='a')
        s[i]='a';
     else if (s[i]!='b' && s[i+1]!='b')
s[i]='b';
else

s[i]='c';

}
}
cout<<s.substr(0,n-1)<<endl;
}