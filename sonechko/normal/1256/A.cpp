#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    while (q--)
    {
        int a,b,n,s;
        cin>>a>>b>>n>>s;
        int t=min(s/n,a);
        s-=t*n;
        if (s>b) cout<<"NO\n"; else cout<<"YES\n";
    }
}