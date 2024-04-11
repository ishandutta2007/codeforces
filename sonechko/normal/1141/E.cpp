#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

const int N = 1e6 + 11;

ll a[N];
ll sum;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll h;
    int n;
    cin>>h>>n;
    ll kol=0,sum=0,ps=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        sum+=a[i];
        if (sum<ps) ps=sum;
        kol++;
        h+=a[i];
        if (h<=0) {cout<<kol<<endl; return 0;}
    }
    if (sum>=0) {cout<<-1<<endl; return 0;}
    ll t=(h+ps)/(abs(sum));
    t=max(0ll,t-2);
    kol+=t*n;
    h+=t*sum;
    for (int j=1; j<=20; j++)
    {
        for (int i=1; i<=n; i++)
        {
            h+=a[i];
            kol++;
            if (h<=0) {cout<<kol<<endl; return 0;}
        }
    }
}