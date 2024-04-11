#include<bits/stdc++.h>
using namespace std;
//#define endl "\n"
#define mp make_pair
#define ss second
#define ff first
#define ull unsigned long long
#define ll long long
#define ld long double
#define pb push_back
const int MOD = 1e9 + 7;
#define mod %MOD


const int N = 2e5 + 11;
map<ull,int> mt;
map<ull,bool> mm;
string t;
int ans;

void rec(int l, ull s, ull p)
{
    if (l==t.size())
    {
        if (mm[s]==0) ans+=mt[s]; mm[s]=1; return;
    }
    if (t[l]=='?')
    {
        rec(l+1,s+5*p,p*29);
        rec(l+1,s+4*p,p*29);
        rec(l+1,s+3*p,p*29);
        rec(l+1,s+2*p,p*29);
        rec(l+1,s+1*p,p*29);
        rec(l+1,s,p);
    } else
    {
        rec(l+1,s+(t[l]-'a'+1)*p,p*29);
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        ull pp=1,ss=0;
        for (int j=0; j<s.size(); j++)
        {
            ss+=(s[j]-'a'+1)*pp;
            pp*=29;
        }
        mt[ss]++;
    }
    for (int jj=1; jj<=m; jj++)
    {
        mm.clear();
        cin>>t;
        ans=0;
        rec(0,0,1);
        cout<<ans<<"\n";
    }
}