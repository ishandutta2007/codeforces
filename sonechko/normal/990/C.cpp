#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 4e5 + 11;

int res[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<int> v;
    for (int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        int kk=0;
        int ps=0;
        for (int j=0; j<s.size(); j++)
        {
            if (s[j]=='(') kk++; else kk--;
            if (kk<0) ps=1;
        }
        if (ps==0) res[kk]++;
        kk=0;
        ps=0;
        for (int j=s.size()-1; j>=0; j--)
        {
            if (s[j]==')') kk++; else kk--;
            if (kk<0) ps=1;
        }
        if (ps==0) v.pb(kk);
    }
    ll ans=0;
    for (int j=0; j<v.size(); j++)
        ans+=1ll*res[v[j]];
    cout<<ans<<endl;
}