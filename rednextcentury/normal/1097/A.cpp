#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    string x;
    bool ok =0;
    for (int i=0;i<5;i++)
    {
        cin>>x;
        if (x[0]==s[0] || x[1]==s[1])ok=1;
    }
    if (ok)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}