#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define y1 skfn

const int N = 4100 + 11;
const int MOD = 1e9 + 7;
#define mod %MOD

int kol[N];
int gg[N];
int kk[N*N];

vector<int> t[N];

ll ans;

void rec(int l, int n, int cc, int p)
{
    if (l>n)
    {
        //cout<<cc<<endl;
        ans+=kk[cc];
        return;
    }
    for (int j=0; j<t[l].size(); j++)
    rec(l+1,n,cc+t[l][j]*p,p*3);
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int w,n,m;
    cin>>w>>n>>m;
    for (int i=1; i<=n; i++)
    {
        ll c;
        cin>>c;
        kol[c]++;
    }
    for (int i=0; i<(1<<w); i++)
    {
        gg[i]=0;
        int x=1;
        for (int j=0; j<=12; j++)
        {
            if (i&(1<<j)) gg[i]+=x;
            x*=3;
        }
    }
    for (int i=0; i<(1<<w); i++)
    for (int j=0; j<(1<<w); j++)
        kk[gg[i]+gg[j]]+=kol[i]*kol[j];
    for (int i=1; i<=m; i++)
    {
        string s;
        cin>>s;
        reverse(s.begin(),s.end());
        for (int j=0; j<s.size(); j++)
        {
            t[j+1].clear();
            if (s[j]=='A'||s[j]=='O'||s[j]=='X') t[j+1].pb(0);
            if (s[j]=='A'||s[j]=='o'||s[j]=='x') t[j+1].pb(1);
            if (s[j]=='X'||s[j]=='a'||s[j]=='o') t[j+1].pb(2);
            //for (int p=0; p<t[j+1].size(); p++)
            //    cout<<t[j+1][p]<<" ";
            //cout<<endl;
        }
        ans=0;
        rec(1,s.size(),0,1);
        cout<<ans<<"\n";
    }
}