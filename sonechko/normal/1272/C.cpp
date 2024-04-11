#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 2e5 + 11;

bool use[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,kk;
    cin>>n>>kk;
    string s;
    cin>>s;
    for (int i=1; i<=kk; i++)
    {
        char c;
        cin>>c;
        use[c-'a']=1;
    }
    ll k=0,ans=0;
    for (int i=0; i<s.size(); i++)
    {
        if (use[s[i]-'a']==1) k++; else k=0;
        ans+=k;
    }
    cout<<ans<<"\n";
}