#include<bits/stdc++.h>
using namespace std;
#define ll long long
unsigned ll a[1000000];
unsigned ll b[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)cin>>a[i],a[n]+=a[i];
    for (int i=0;i<m;i++)cin>>b[i],b[m]+=b[i];
    sort(a,a+n);sort(b,b+m);
    unsigned ll c1 = b[m];
    for (int i=0;i<n-1;i++){
        c1 += min(a[i], b[m]);
    }
    unsigned ll c2 = a[n];
    for (int i=0;i<m-1;i++){
        c2 += min(b[i], a[n]);
    }
    unsigned ll c3=0;
    for (int i=0;i<n;i++){
        c3+=min(b[m],a[i]*m);
    }
    unsigned ll c4=0;
    for (int i=0;i<m;i++){
        c4+=min(a[n],b[i]*n);
    }
    cout<<min(min(c1,c2),min(c3,c4))<<endl;
}