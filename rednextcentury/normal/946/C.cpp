#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    char cur='a';
    for (int i=0;i<s.size();i++)
    {
        if (s[i]<=cur)
        {
            s[i]=cur;
            cur++;
        }
        if(cur>'z')break;
    }
    if (cur>'z')
        cout<<s<<endl;
    else cout<<"-1"<<endl;
}