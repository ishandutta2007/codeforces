#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int ret=0;
    while(n--)
    {
        string s;
        cin>>s;
        if (s[0]=='T')ret+=4;
        else if (s[0]=='C')ret+=6;
        else if (s[0]=='O')ret+=8;
        else if (s[0]=='D')ret+=12;
        else ret+=20;
    }
    cout<<ret<<endl;
}