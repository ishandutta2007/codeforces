#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 11;

int main()
{
    string s;
    cin>>s;
    s+="    ";
    ll kol1=0,ans=0;
    for (int i=s.size()-5; i>=0; i--)
        if (s[i]=='h'&&s[i+1]=='e'&&s[i+2]=='a'&&s[i+3]=='v'&&s[i+4]=='y')
    ans+=kol1; else
        if (s[i]=='m'&&s[i+1]=='e'&&s[i+2]=='t'&&s[i+3]=='a'&&s[i+4]=='l')
    kol1++;
    cout<<ans<<endl;
}