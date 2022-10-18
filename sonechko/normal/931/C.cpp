#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define ld long double

const int N = 2e5 + 11;

map<int,int> mt;

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    ll min1=100000,max1=-100000;
    for (int i=1; i<=n; i++)
    {
           ll l;
           cin>>l;
           mt[l]++;
           min1=min(min1,l);
           max1=max(max1,l);
    }
    ll kol1=mt[min1],kol2=mt[min1+1],kol3=mt[min1+2];
    ll sum=kol1*min1+kol2*(min1+1)+kol3*(min1+2);
    if (max1-min1<=1)
    {
              cout<<n<<endl;
              for (int i=1; i<=kol1; i++)
              cout<<min1<<" ";
              for (int i=1; i<=kol2; i++)
              cout<<max1<<" ";
              cout<<endl;
              return 0;
    }
    int kk1=kol1,kk2=kol2,kk3=kol3,rr=n;
    for (ll k1=0; k1<=n; k1++)
    {
              ll ss=sum-k1*min1;
              ss-=(n-k1)*1ll*(min1+1);
              ll k3=ss;
              ll k2=n-ss-k1;
              if (k2<0||k3<0) continue;
              int pp=min(k1,kol1)+min(k2,kol2)+min(k3,kol3);
              if (pp<rr&&k1+k2+k3==n) {rr=pp; kk1=k1; kk2=k2; kk3=k3;}
    }
    cout<<rr<<endl;
    for (int i=1; i<=kk1; i++)
    cout<<min1<<" ";
    for (int i=1; i<=kk2; i++)
    cout<<min1+1<<" ";
    for (int i=1; i<=kk3; i++)
    cout<<min1+2<<" ";
    cout<<endl;
}