#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back

const int N = 1e5 + 11;

int a[N];
int kol[N],use[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int kk=0;
    for (int i=1; i<=n; i++)
    {
        kol[a[i]]++;
        if (kol[a[i]]==1) kk++;
    }
    ll ans=0;
    for (int i=1; i<=n; i++)
    {
        use[a[i]]++;
        kol[a[i]]--;
        if (kol[a[i]]==0) kk--;
        if (use[a[i]]==1) ans+=1ll*kk;
    }
    cout<<ans<<endl;
}