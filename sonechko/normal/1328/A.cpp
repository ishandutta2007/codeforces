#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ld long double

const int N = 1e5 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        ll a,b;
        cin>>a>>b;
        if (a%b==0) cout<<0<<"\n";
        else cout<<(b-a%b)<<"\n";
    }
}