#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    int ret=0,cur=0;
    for (int i=0;i<s.size();i++)
        if (s[i]=='(')cur++;
        else if (cur)cur--,ret+=2;
    cout<<ret<<endl;
}