#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 11;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

int k[N][27];
int kk[27];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    s="."+s;
    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<=26; j++)
            k[i][j]=k[i-1][j];
        k[i][s[i]-'a']++;
    }
    int m;
    cin>>m;
    for (int i=1; i<=m; i++)
    {
        string s;
        cin>>s;
        for (int j=0; j<=26; j++)
            kk[j]=0;
        for (int j=0; j<s.size(); j++)
        kk[s[j]-'a']++;
        int l=1,r=n;
        while (r-l>1)
        {
            int mid=(l+r)/2;
            int t=0;
            for (int j=0; j<=26; j++)
                if (k[mid][j]<kk[j]) t=1;
            if (t==0) r=mid; else l=mid;
        }
        int t=0;
        for (int j=0; j<=26; j++)
            if (k[l][j]<kk[j]) t=1;
        if (t==0) cout<<l<<"\n"; else cout<<r<<"\n";
    }
}