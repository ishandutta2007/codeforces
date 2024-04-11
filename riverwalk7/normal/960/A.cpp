#include <iostream>
#include <fstream>
using namespace std;
string s;
int a, b, c;
int main()
{
    cin>>s;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='a')
        {
            ++a;
        }
        if(s[i]=='b')
        {
            ++b;
        }
        if(s[i]=='c')
        {
            ++c;
        }
        if(i >= 1 && s[i-1] > s[i])
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    if(a==0||b==0)
    {
        cout<<"NO"<<endl;
    }
    else if(a!=c&&b!=c)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
    }
}