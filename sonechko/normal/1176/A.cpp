#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long

const int N = 2e5 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    for (int i=1; i<=q; i++)
    {
        ll n;
        cin>>n;
        int ans=0;
        while (n>1)
        {
            ans++;
            if (n%2==0) n/=2; else
            if (n%3==0) {n/=3; n*=2;} else
            if (n%5==0) {n/=5; n*=4;} else {ans=-1; break;}
        }
        cout<<ans<<"\n";
    }
}