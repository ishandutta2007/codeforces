#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair

const int N = 3e5 + 11;

pair<ll,ll> try_(ll a, ll b)
{
    if (a>b) swap(a,b);
   /**
   n-n/m=a
   n+n/m=b

   n/m+a+n/m  = b
   **/
   ll d=(b-a);
   if (d%2==1) return mp(-1,-1);
   int pp=d/2;
   if (pp==0) return mp(-1,-1);
   int x=pp+a;
   int y=x/pp;
   if (x<=0||y<=0) return mp(-1,-1);
   if (x-(x/y)==a&&x+(x/y)==b) return mp(x,y);
   return mp(-1,-1);
}
int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for (int pp=1; pp<=t; pp++)
    {
        ll x;
        cin>>x;
        if (x==0) {cout<<"1 1"<<endl;
        continue;}
        ll d=2;
        int tr=0;
        for (int d=1; d<=(int)sqrt(x); d++)
        if (x%d==0)
        {
            pair<ll,ll> p=try_(d,x/d);
            if (p.ff!=-1)
            {
                tr=1;
                cout<<p.ff<<" "<<p.ss<<endl;
                break;
            }
        }
        if (tr==0) {cout<<-1<<endl;
        }
    }
}
/**

n m -- (n/m)*(n/m)

x = n*n-(n/m)*(n/m) = (n-n/m)(n+n/m) = X

n-n/m = d
n+n/m = x/d

n = n/m + d

n/m = (x/d - d)/2


21

**/