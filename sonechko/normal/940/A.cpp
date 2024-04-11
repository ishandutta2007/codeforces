#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ss second
#define ff first
#define endl "\n"
#define ld long double
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;

const int N = 100 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,d;
    cin>>n>>d;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int ans=n;
    for (int i=1; i<=n; i++)
    {
        int kol=0;
        for (int j=1; j<=n; j++)
            if (a[j]<a[i]||a[j]>a[i]+d) kol++;
        ans=min(ans,kol);
    }
    cout<<ans<<endl;
}