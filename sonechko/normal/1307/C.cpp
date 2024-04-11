#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 25 + 11;

ll k1[N],k2[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    s="."+s;
    ll ans=0;
    int n=s.size()-1;
    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<26; j++)
            k2[j][s[i]-'a']+=k1[j];
        k1[s[i]-'a']++;
    }
    for (int i=0; i<26; i++)
        ans=max(ans,k1[i]);
    for (int i=0; i<26; i++)
    for (int j=0; j<26; j++)
        ans=max(ans,k2[i][j]);
    cout<<ans;
}