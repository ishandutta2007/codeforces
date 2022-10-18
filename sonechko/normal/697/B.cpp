#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 11;
int main()
{
    string s;
    cin>>s;
    string t="";
    s='.'+s;
    int k=0,t1=0,h=0;
    for (int i=1; i<s.size(); i++)
    {
        if (s[i]=='.') {k=i;} else
        if (s[i]=='e') {t1=i;} else
        if (t1!=0) {h=h*10+(s[i]-'0');} else
        t=t+s[i];
    }
    int c=k-1+h;
    if (c>=t.size())
    {
        cout<<t;
        for (int i=1; i<=c-t.size(); i++)
            cout<<0;
        cout<<endl;
    } else
    {
        int k=0;
        for (int i=c; i<t.size(); i++)
            if (t[i]!='0') k=1;
        for (int i=0; i<c; i++)
            cout<<t[i];
        if (k==1)
        {
        cout<<'.';
        for (int i=c; i<t.size(); i++)
            cout<<t[i];
        cout<<endl;
        }
    }
}