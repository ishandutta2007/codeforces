#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define ss second
#define ff first
#define ld long double
const ll N = 1e6 + 11;
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll a,b;
    int c;
    cin>>a>>b>>c;
    for (int p=1; p<=1000000; p++)
    {
        a*=10;
        if (a/b==c) {cout<<p<<endl; return 0;}
        a%=b;
        if (a==0&&c==0) {cout<<p+1<<endl; return 0;}
        if (a==0) break;
    }
    cout<<-1<<endl;
}