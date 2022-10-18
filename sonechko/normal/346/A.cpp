#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

const int N = 2e5 + 11;
const int MOD = 1e6 + 3;
#define mod %MOD

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int l=0,k=0;
    for (int i=1; i<=n; i++)
    {
        int r;
        cin>>r;
        k=max(k,r);
        l=__gcd(l,r);
    }
    int p=k/l-n;
    if (p%2==1) cout<<"Alice"<<endl; else cout<<"Bob"<<endl;
}