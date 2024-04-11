#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define s second
#define ll long long
#define f first
#define mp make_pair
#define pb push_back
int r[N],c[N];
int main()
{
    sync;
    #ifdef LOCAL
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    #else
    #endif
    int n,m,k;
    cin>>n>>m>>k;
    string s;
    cin>>s;
    s='.'+s;
    if (s[m]==s[k]) {cout<<0<<endl; return 0;}
    for (int i=1; i<=n; i++)
        if (s[i]=='1') r[i]=i; else r[i]=r[i-1];
    for (int i=n; i>=1; i--)
        if (s[i]=='1') c[i]=i; else c[i]=c[i+1];
    int ans=INT_MAX;
    for (int i=1; i<=n; i++)
        if (s[i]=='0')
    ans=min(ans,min(abs(i-c[i]),abs(i-r[i])));
    cout<<ans<<endl;
}