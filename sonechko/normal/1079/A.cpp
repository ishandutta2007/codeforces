#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ll long long

const int N = 1e6 + 11;
const int MOD = 1e9 + 7;

int a[N],kol[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    int t=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        kol[a[i]]++;
        t=max(t,kol[a[i]]);
    }
    t=(t+k-1)/k;
    t*=k;
    int ans=0;
    for (int i=1; i<=100; i++)
        if (kol[i]>0) ans+=t-kol[i];
    cout<<ans<<endl;
}
/**
1 1
3 3 3
5 5 5 5
100
**/