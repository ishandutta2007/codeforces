#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define ff first
#define ss second

const ll N = 1e6 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    cout.precision(10);
    cout<<fixed;
    for (int i=1; i<=t; i++)
    {
        ld d;
        cin>>d;
        ld l=2,r=1000;
        for (int p=1; p<=100; p++)
        {
            ld mid=(l+r)/2;
            if (mid*(d-mid)>d) l=mid; else r=mid;
        }
        if (d==0) cout<<"Y 0.00000000 0.00000000\n"; else
        if (d-l*(d-l)<=0.000000001)
        {
            cout<<"Y "<<l<<" "<<d-l<<"\n";
        }  else cout<<"N\n";
    }
}
/**
a + b = d
a * b = d

a = d-b

(d-b)*b=d
d*b - b*b = d
d*b-d=b*b
d*(b-1)=b*b
d=b*b
  ---
  b-1
**/