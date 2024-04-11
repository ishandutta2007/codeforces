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
    int t;
    cin>>t;
    for (int j=1; j<=t; j++)
    {
        ll x;
        cin>>x;
        ll s=1+2+3+4+5+6;
        if (x<s-6) cout<<"NO\n"; else
        if ((x-(s-6))%14==0||
            (x-(s-5))%14==0||
            (x-(s-4))%14==0||
            (x-(s-3))%14==0||
            (x-(s-2))%14==0||
            (x-(s-1))%14==0) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
/**

**/