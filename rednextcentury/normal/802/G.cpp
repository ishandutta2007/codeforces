#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    string t="heidi";
    int cur=0;
    for (int i=0;i<s.size();i++)
    {
        if (s[i]==t[cur])cur++;
        if (cur==t.size())
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}