#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    long long w=0,wo=0,wow=0;
    for (int i=0;i<s.size();i++)
    {
        if (i && s[i]=='v' && s[i-1]=='v') wow+=wo,w++;
        if (s[i]=='o')wo+=w;
    }
    cout<<wow<<endl;
}