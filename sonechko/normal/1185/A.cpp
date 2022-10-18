#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int ans=0;
    if (a>b) swap(a,b);
    if (b>c) swap(b,c);
    if (a>b) swap(a,b);
    if (a>b-d) {ans+=a-(b-d);}
    if (c<b+d) {ans+=(b+d)-c;}
    cout<<ans;
}