#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define ull unsigned long long
#define mp make_pair
const int N = 2000 + 11;

int kol[N];

int main()
{
    #ifndef __WIN32
    freopen("twopaths.in", "r", stdin);
    freopen("twopaths.out", "w", stdout);
    #endif // __WIN32
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        kol[l]++;
        kol[r]++;
    }
    int ans=0;
    for (int i=1; i<=n; i++)
        if (kol[i]==1) ans++;
    cout<<ans<<endl;
}