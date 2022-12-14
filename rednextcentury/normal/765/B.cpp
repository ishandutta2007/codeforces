#include<bits/stdc++.h>
using namespace std;
string s;
void rep(char a,char b)
{
    for (int i=0;i<s.size();i++)
        if (s[i]==a)
            s[i]=b;
}
int main()
{
    cin>>s;
    string y=s;
    for (int i=0;i<s.size();i++)
        s[i]=toupper(s[i]);
    char x='a';
    for (int i=0;i<s.size();i++)
        if (s[i]!=tolower(s[i]))
            rep(s[i],x++);
    if (y==s)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}