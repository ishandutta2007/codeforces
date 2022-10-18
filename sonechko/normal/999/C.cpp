#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 4e5 + 11;
const int MOD = 1e9 + 7;
const int MX = 2e18;

#define mod %MOD

bool use[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    vector<pair<char,int> > vv;
    string s;
    cin>>s;
    for (int i=0; i<s.size(); i++)
        vv.pb(mp(s[i],i));
    sort(vv.begin(),vv.end());
    for (int i=0; i<k; i++)
        use[vv[i].ss]=1;
    for (int i=0; i<s.size(); i++)
        if (use[i]==0) cout<<s[i];
}


/// 999 C