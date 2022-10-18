#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

const int N = 3e5 + 11;
const int MOD = 1e9 + 7;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        int ans=s.size();
        for (int j=0; j<s.size(); j++)
        {
            if (s[j]!='0') break;
            ans--;
        }
        for (int j=s.size()-1; j>=0; j--)
        {
            if (s[j]!='0') break;
            ans--;
        }
        for (int i=0; i<s.size(); i++)
            if (s[i]=='1') ans--;
        ans=max(ans,0);
        cout<<ans<<"\n";
    }
}