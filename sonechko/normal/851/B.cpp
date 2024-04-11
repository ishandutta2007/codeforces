#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define ld long double
#define pb push_back
const int MOD = 1e9 + 7;
#define mod %MOD



const int N = 2e5 + 11;

ll dist(ll x1, ll y1, ll x2, ll y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
bool g(ld a, ld b)
{
    if (abs(a-b)<=0.000001) return true;
    return false;
}
int main() {
    ll a1,a2,b1,b2,c1,c2;
    cin>>a1>>a2>>b1>>b2>>c1>>c2;
    ll a=dist(a1,a2,b1,b2);
    ll b=dist(b1,b2,c1,c2);
    if (a!=b||(a1-b1)*(b2-c2)==(b1-c1)*(a2-b2)) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}