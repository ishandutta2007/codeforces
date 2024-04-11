#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        if (n==2 && s[0]>=s[1])
            cout<<"NO"<<endl;
        else cout<<"YES\n"<<2<<endl<<s[0]<<' '<<s.substr(1,s.size())<<endl;
    }
}