#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t>0)
    {
        t--;
        ll n,v,l,r;
        cin>>n>>v>>l>>r;
        cout<<n/v-(r/v-(l-1)/v)<<endl;
    }
}