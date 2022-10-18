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
    ll n;
    cin>>n;
    ll nn=n;
    vector<ll> vv;
    ll d=2;
    while (d*d<=n)
    {
        if (n%d==0) vv.pb(d);
        while (n%d==0)
            n/=d;
        d++;
    }
    if (n>1) vv.pb(n);
    if (vv.size()==1&&vv.back()==nn) return cout<<nn, 0;
    if (vv.size()==1) return cout<<vv.back(), 0;
    cout<<1;
}
/**
8 - 2 * 2 * 2
2 4
1-3
2-4
3-5
4-6
5-7
6-8
1-5
2-6
3-7
4-8

1,3,7,5
2,4,6,8

9 - 3 * 3


**/