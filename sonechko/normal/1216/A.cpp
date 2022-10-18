#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans=0;
    for (int i=1; i<s.size(); i+=2)
    {
        if (s[i]=='a'&&s[i-1]=='a') {ans++; s[i]='b';} else
        if (s[i]=='b'&&s[i-1]=='b') {ans++; s[i]='a';}
    }
    cout<<ans<<endl;
    cout<<s<<endl;
}