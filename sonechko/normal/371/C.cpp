#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll a,b,c;
    a=b=c=0;
    string s;
    cin>>s;
    for (int i=0; i<s.size(); i++)
        if (s[i]=='B') a++; else
        if (s[i]=='S') b++; else c++;
    ll aa,bb,cc,pa,pb,pc,rr;
    cin>>aa>>bb>>cc>>pa>>pb>>pc>>rr;
    ll l=0,r=1e15;
    while (r-l>1)
    {
        ll mid=(l+r)/2;
        ll ks=max(0LL,mid*a-aa)*pa+max(0LL,mid*b-bb)*pb+max(0LL,mid*c-cc)*pc;

        if (ks<=rr) l=mid; else r=mid;
    }
    ll mid=r;
    ll ks=max(0LL,mid*a-aa)*pa+max(0LL,mid*b-bb)*pb+max(0LL,mid*c-cc)*pc;
    if (ks<=rr) cout<<r<<endl; else cout<<l<<endl;
}