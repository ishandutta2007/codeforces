#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 11;
int a[N];
int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    ll b,c,d,e,f;
    cin>>b>>c>>d>>e>>f;
    ll ans=0,bb=0,cc=0,dd=0,ee=0,ff=0;
    for (int i=1; i<=n; i++)
    {
        ans+=a[i];
        int p;
        p=ans/f;
        ff+=p;
        ans-=p*f;
        p=ans/e;
        ee+=p;
        ans-=p*e;
        p=ans/d;
        dd+=p;
        ans-=p*d;
        p=ans/c;
        cc+=p;
        ans-=p*c;
        p=ans/b;
        bb+=p;
        ans-=p*b;
    }
    cout<<bb<<" "<<cc<<" "<<dd<<" "<<ee<<" "<<ff<<endl;
    cout<<ans<<endl;
}