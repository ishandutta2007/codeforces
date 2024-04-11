#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mod %MOD

const int N = 4000 + 11;
const int MOD = 1e9 + 7;

int kol[10][N];
vector<int> vv;
map<int,int> mt;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a;
    cin>>a;
    string s;
    cin>>s;
    int n=s.size();
    s="."+s;
    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<=9; j++)
            kol[j][i]=kol[j][i-1];
        kol[s[i]-'0'][i]++;
    }
    for (int i=1; i<=n; i++)
    for (int j=i; j<=n; j++)
    {
        int ss=0;
        for (int p=1; p<=9; p++)
            ss+=(kol[p][j]-kol[p][i-1])*p;
        vv.pb(ss);
        mt[ss]++;
    }
    ll ans=0;
    for (int j=0; j<vv.size(); j++)
        if (vv[j]!=0&&a%vv[j]==0) ans+=1ll*mt[a/vv[j]]; else
        if (a==0&&vv[j]==0) ans+=1ll*n*1ll*(n+1)/2ll;
    cout<<ans<<endl;
}