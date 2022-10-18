#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

ll a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>k>>n;
    int p=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        a[i]%=2;
        if (k%2==0&&i==n) p=(p+a[i])%2; else
        if (k%2==1) p=(p+a[i])%2;
    }
    if (p==1) cout<<"odd"; else cout<<"even";
}