#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 3e5 + 11;


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n,x,y;
    cin>>n>>x>>y;
    ll p1=max(x-1,y-1);
    ll p2=max(n-x,n-y);
    if (p1<=p2) cout<<"White"<<endl; else cout<<"Black"<<endl;
}