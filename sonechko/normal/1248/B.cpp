#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 4e5 + 11;
const int MOD = 1e9 + 7;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    ll l=n/2;
    sort(a+1,a+n+1);
    ll s1=0,s2=0;
    for (int i=1; i<=l; i++)
        s1+=a[i];
    for (int i=l+1; i<=n; i++)
        s2+=a[i];
    cout<<s1*s1+s2*s2<<endl;
}
/**
**/