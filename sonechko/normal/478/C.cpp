#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ss second
#define ff first
#define pb push_back
#define mp make_pair
#define y1 kdnfskefn
#define sqr(a) ((a)*(a))
const int N = 1e2 + 11;
///-----------------------------------------------------------
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll l,r,k;
    cin>>l>>r>>k;
    if (max(l,max(r,k))-min(l,min(r,k))<=1) cout<<(l+r+k)/3<<endl; else
    if (max(l,max(r,k))>=2*(l+r+k-max(l,max(r,k)))) cout<<l+r+k-max(l,max(r,k))<<endl;
    else cout<<(l+r+k)/3<<endl;
}
/**
100 99 56
44 43

**/