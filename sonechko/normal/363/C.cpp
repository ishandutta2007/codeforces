#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N = 1e3 + 11;
int a[N];
int main()
{
    string s;
    cin>>s;
    string t="";
    for (int i=0; i<s.size(); i++)
    if (t.size()<=1) t+=s[i]; else
    if (s[i]!=t[t.size()-1]||s[i]!=t[t.size()-2])
    {
        if (t.size()>=3&&t[t.size()-1]==s[i]&&
            t[t.size()-2]==t[t.size()-3]) {} else
                t+=s[i];
    }
    cout<<t<<endl;
}