#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int a,b,c,r;
        cin>>a>>b>>c>>r;
        int c1=c-r,c2=c+r;
        if (a>b) swap(a,b);
        if (a>=c1&&b<=c2) cout<<0<<"\n"; else
        if (c1>b||c2<a) cout<<b-a<<"\n"; else
        if (a<c1&&b<=c2) cout<<c1-a<<"\n"; else
        if (b>c2&&a>=c1) cout<<b-c2<<"\n"; else
        if (a<=c1&&c2<=b) cout<<c1-a+b-c2<<"\n"; else cout<<0<<"\n";
    }
}