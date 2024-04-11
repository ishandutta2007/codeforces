#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define ff first
#define ss second
const ll N = 1e6 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    ld p=100000000000000;
    for (int i=1; i<=n; i++)
    {
        int l,r;
        cin>>l>>r;
        ld c=(ld)l/(ld)r;
        p=min(p,c);
    }
    cout.precision(10);
    cout<<fixed;
    cout<<p*(ld)m<<endl;
}