#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
const int N = 1e6 + 11;

bool good(int l)
{
    l%=24*60;
    int a=l/60;
    int b=l%60;
    if (a%10==7||a/10==7||b%10==7||b/10==7) return true;
    return false;
}

int pred(int l, int r, int x)
{
    for (int i=1; i<=24*60; i++)
    {
        if (l==r) return i-1;
        l+=x;
        l%=24*60;
    }
    return 24*60;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x,a,b;
    cin>>x>>a>>b;
    int ans=24*60;
    for (int d=0; d<24*60; d++)
        if (good(d))
    {
        int p=pred(d,a*60+b,x);
        ans=min(ans,p);
    }
    cout<<ans<<endl;
}