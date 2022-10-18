#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define ld long double

const int N = 2e5 + 11;

int kol[N],dep[N],p[N];


int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    kol[0]=1;
    int ans=0;
    for (int i=2; i<=n; i++)
    {
        cin>>p[i];
        dep[i]=dep[p[i]]+1;
        kol[dep[i]]^=1;
    }
    for (int i=0; i<=n; i++)
    ans+=kol[i]%2;
    cout<<ans<<endl;
}