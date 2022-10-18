#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

const int N = 5e5 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll a,b,c;
    cin>>a>>b>>c;
    ll kol=c*2;
    ll t=min(a,b);
    kol+=t*2;
    a-=t;
    b-=t;
    if (a>0||b>0) kol++;
    cout<<kol<<endl;
}