#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int a=0,b=0,c=0;
    string B=s;
    for (int i=0;i<s.size();i++)
    {
        if (s[i]=='a')
            a++;
        else if (s[i]=='b')
            b++;
        else if (s[i]=='c')
            c++;
    }
    sort(B.begin(),B.end());
    if ((a+b+c)!=s.size() || B!=s || a==0 || b==0 || c==0)
    {
        cout<<"NO"<<endl;
    }
    else if (a==c || b==c)
    {
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}