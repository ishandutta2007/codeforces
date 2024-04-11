#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll p[100];
ll s[100];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    p[0]=1;
    s[0]=1;
    for (int i=1;i<=38;i++)p[i]=p[i-1]*3;
    for (int i=1;i<=38;i++)s[i]=p[i]+s[i-1];

    while(t--)
    {
        ll n;
        cin>>n;
        ll m=0;
        for (int i=38;i>=1;i--) {
            if (s[i-1]>=n)continue;
            n-=p[i];
            m+=p[i];
        }
        if(n>0)m+=p[0];
        cout<<m<<endl;
    }
}