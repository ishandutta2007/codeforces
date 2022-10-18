#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 11;
#define pb push_back


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s,t;
    cin>>s>>t;
    string f;
    cin>>f;
    for (int i=0; i<f.size(); i++)
    {
        char ch=f[i];
        if (ch>='a'&&ch<='z')
        {
            for (int j=0; j<s.size(); j++)
            if (s[j]==ch) cout<<t[j];
        } else
        if (ch>='A'&&ch<='Z')
        {
            for (int j=0; j<s.size(); j++)
            if (s[j]==char(ch+32)) cout<<char(t[j]-32);
        } else cout<<ch;
    }
}