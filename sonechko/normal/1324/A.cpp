#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long

const int N = 2e5 + 11;




void up()
{
    int n;
    cin>>n;
    int k1=0,k2=0;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        if (l%2==0) k1++; else k2++;
    }
    if (k1==n||k2==n) cout<<"YES\n"; else cout<<"NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}