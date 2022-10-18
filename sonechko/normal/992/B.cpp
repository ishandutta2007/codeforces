#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ff first
#define ss second
#define pb push_back

const int N = 2e5 + 11;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int l,r,x,y;
    cin>>l>>r>>x>>y;
    if (y%x!=0) {cout<<0<<endl; return 0;}
    y/=x;
    int ans=0;
    for (int p=1; p<=sqrt(y); p++)
        if (y%p==0)
    {
        int c=p;
        int d=y/p;
        if (__gcd(c,d)==1&&l<=c*x&&c*x<=r&&l<=d*x&&d*x<=r)
        {
            if (c==d) ans++; else ans+=2;
        }
    }
    cout<<ans<<endl;
}