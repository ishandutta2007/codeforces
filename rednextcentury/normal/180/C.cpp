#include <bits/stdc++.h>
using namespace std;
int upp[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    s="."+s;
    for (int i=1;i<s.size();i++)
        upp[i]=isupper(s[i])+upp[i-1];
    int tot = upp[s.size()-1];
    int ret=1e9;
    for (int i=0;i<s.size();i++)
        ret = min(ret,(i-upp[i])+(tot-upp[i]));
    cout<<ret<<endl;
}