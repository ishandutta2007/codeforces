#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int k=0;
    for (int i=0; i<s.size()-1; i++)
    if (s[i]=='r'&&s[i+1]=='u') {k=i;}
    if (s[0]=='h')
    {
        cout<<"http://";
        for (int j=4; j<k; j++)
            cout<<s[j];
        cout<<".ru";
        if (k!=s.size()-2)
        {
            cout<<"/";
            for (int j=k+2; j<s.size(); j++)
                cout<<s[j];
        }
    } else
    {

        cout<<"ftp://";
        for (int j=3; j<k; j++)
            cout<<s[j];
        cout<<".ru";
        if (k!=s.size()-2)
        {
            cout<<"/";
            for (int j=k+2; j<s.size(); j++)
                cout<<s[j];
        }
    }
}