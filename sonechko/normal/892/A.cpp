#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ss second
#define ff first
#define endl "\n"
#define ld long double
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;
#define mod %MOD


const int N = 1e5 + 11;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    ll res=0,max1=0,max2=0;
    for (int i=1; i<=n; i++)
    {
        ll l;
        cin>>l;
        res+=l;
    }
    for (int i=1; i<=n; i++)
    {
        ll l;
        cin>>l;
        if (l>max1) {max2=max1; max1=l;} else
        if (l>max2) {max2=l;}
    }
    if (res<=max1+max2) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}