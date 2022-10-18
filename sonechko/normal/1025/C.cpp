#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 5e5 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int n=s.size();
    s="."+s+s;
    int kol=1,ans=1;
    for (int i=s.size()-2; i>=1; i--)
    {
        if (s[i]==s[i+1]) kol=1; else kol++;
        ans=max(ans,min(n,kol));
    }
    cout<<ans<<endl;
}