#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define mp make_pair
#define ff first
#define ss second

const int MOD = 998244353;
const int N = 1e6 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    cout.precision(10);
    cout<<fixed;
    while (t--)
    {
        ld a,b;
        cin>>a>>b;
        if (b==0) cout<<1<<"\n"; else
        if (a==0) cout<<0.5<<"\n"; else
        if (a<b*4)
        {
            ld s=a*b*2;
            ld c1=b,c2=b-a/4;
            c1+=c2;
            c2=a;
            ///cout<<c1<<" "<<c2<<endl;
            ld s1=c1*c2/2;
            cout<<(s-s1)/s<<"\n";
        } else
        {
            ld s=a*b*2;
            ld s1=b*b*2;
            cout<<(s-s1)/s<<"\n";
        }
    }
}