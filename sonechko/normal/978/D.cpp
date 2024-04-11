#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

const int N = 2e5 + 11;

int n;
ll b[N],c[N];

int good(ll ps)
{
    int pr=0;
    for (int i=2; i<=n; i++)
    {
        c[i]=c[i-1]+ps;
        if (abs(c[i]-b[i])>1) return 1e9;
        if (abs(c[i]-b[i])!=0) pr++;
    }
    return pr;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>b[i];
    int res=1e9;
    c[1]=b[1]-1;
    res=min(res,good(b[2]-c[1])+1);
    res=min(res,good(b[2]-c[1]-1)+1);
    res=min(res,good(b[2]-c[1]+1)+1);
    c[1]=b[1];
    res=min(res,good(b[2]-c[1]));
    res=min(res,good(b[2]-c[1]-1));
    res=min(res,good(b[2]-c[1]+1));
    c[1]=b[1]+1;
    res=min(res,good(b[2]-c[1])+1);
    res=min(res,good(b[2]-c[1]-1)+1);
    res=min(res,good(b[2]-c[1]+1)+1);
    if (res==1000000000) cout<<-1; else cout<<res;
}