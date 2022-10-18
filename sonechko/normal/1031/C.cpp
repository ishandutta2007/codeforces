#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define mod %MOD

const int MOD = 1e9 + 7;
const int N = 1e5 + 11;

ll a,b;

bool good(ll x)
{
    if (x*(x+1)/2>a+b) return false;
    ll t1=0,t2=0;
    for (int i=x; i>=1; i--)
        if (t1+i<=a) t1+=i; else t2+=i;
    if (t1<=a&&t2<=b) return true;
    return false;
}

void up(int x)
{
    vector<int> v1,v2;
    int t1=0,t2=0;
    for (int i=x; i>=1; i--)
        if (t1+i<=a) {t1+=i; v1.pb(i);} else {t2+=i; v2.pb(i);}
    cout<<v1.size()<<endl;
    for (int i=0; i<v1.size(); i++)
        cout<<v1[i]<<" ";
    cout<<endl;
    cout<<v2.size()<<endl;
    for (int i=0; i<v2.size(); i++)
        cout<<v2[i]<<" ";
    cout<<endl;

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>a>>b;
    ll l=0,r=100000;
    while (r-l>1)
    {
        ll mid=(l+r)/2;
        if (good(mid)) l=mid; else r=mid;
    }
    if (good(r)) up(r);
    up(l);
}