#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 2e5 + 11;

int kk[N][30];

void up()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    s="."+s;
    for (int i=1; i<=k; i++)
    for (int j=0; j<=26; j++)
        kk[i][j]=0;
    for (int i=1; i<=n; i++)
    {
        int ks=(i+k-1)/k;
        int pos=i-(ks-1)*k;
        kk[min(pos,k-pos+1)][s[i]-'a']++;
    }
    int ans=0;
    for (int i=1; i<=(k+1)/2; i++)
    {
        int kol_all=0,kol_max=0;
        for (int j=0; j<26; j++)
        {
            kol_all+=kk[i][j];
            kol_max=max(kol_max,kk[i][j]);
        }
        ans+=kol_all-kol_max;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    while (q--) up();
}
/**


**/