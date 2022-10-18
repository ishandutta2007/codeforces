#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;
const int P1 = 31;
const int P2 = 29;
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;

int kol1[N],kol2[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    s="."+s;
    for (int i=1; i<=n; i++)
    if (s[i]=='G') kol1[i]=kol1[i-1]+1; else kol1[i]=0;
    for (int i=n; i>=1; i--)
    if (s[i]=='G') kol2[i]=kol2[i+1]+1; else kol2[i]=0;
    int kol=0;
    for (int i=1; i<=n; i++)
        if (s[i]=='G') kol++;
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        ans=max(ans,kol1[i]);
        ans=max(ans,kol2[i]);
        if (s[i]=='S'&&kol1[i-1]+kol2[i+1]<kol)
            ans=max(ans,kol1[i-1]+kol2[i+1]+1);
        if (s[i]=='S'&&kol1[i-1]+kol2[i+1]==kol)
            ans=max(ans,kol);
    }
    cout<<ans<<endl;
}