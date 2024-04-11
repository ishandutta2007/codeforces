#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
const int MOD = 1e9 + 7;
#define mod %MOD

const int N = 1e5 + 11;

int n,a[N],b[N];

void up(ll x1, ll y1, ll x2, ll y2)
{
    ll a1=y1-y2;
    ll b1=x2-x1;
    ll c1=-x1*a1-y1*b1;
    ll dx1=2000000000,dx2=2000000000;
    ll a2=3000000000,b2,c2;
    for (int i=1; i<=n; i++)
        if (a1*a[i]+b1*b[i]+c1!=0)
        {
            if (dx1==2000000000) {dx1=a[i]; dx2=b[i];} else
            if (a2==3000000000) {a2=dx2-b[i]; b2=a[i]-dx1; c2=-a[i]*a2-b[i]*b2;} else
            if (a2*a[i]+b2*b[i]+c2!=0) return;
        }
        cout<<"YES"<<endl;
        exit(0);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i]>>b[i];
    if (n<=3) {cout<<"YES"<<endl; return 0;}
    up(a[1],b[1],a[2],b[2]);
    up(a[1],b[1],a[3],b[3]);
    up(a[2],b[2],a[3],b[3]);
    cout<<"NO"<<endl;
}