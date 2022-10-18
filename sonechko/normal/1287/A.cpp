#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int k;
        cin>>k;
        string s;
        cin>>s;
        int kk=-1,ans=0;
        for (int i=0; i<s.size(); i++)
        {
            if (s[i]=='A') kk=0; else
            if (s[i]=='P'&&kk>=0) kk++;
            ans=max(ans,kk);
        }
        cout<<ans<<"\n";
    }
}