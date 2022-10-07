#include<bits/stdc++.h>
using namespace std;
main()
{
    string s;
    cin>>s;
    int z=0;
    int c=0;
    for (int i=0; i<s.size(); i++)
    {
        if(c==1 && s[i]=='0') z++;
        if(s[i]=='1') c=1;
    }
    if(z>=6) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}