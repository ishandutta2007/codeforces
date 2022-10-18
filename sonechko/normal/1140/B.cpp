#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int N = 2e5 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for (int i=1; i<=t; i++)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ans=n-1;
        for (int j=0; j<s.size(); j++)
            if (s[j]=='>') ans=min(ans,j);
        for (int j=s.size()-1; j>=0; j--)
            if (s[j]=='<') ans=min(ans,(int)s.size()-j-1);
        cout<<ans<<"\n";
    }
}
/**
<<>>
**/