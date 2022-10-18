#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long

const int N = 2e5 + 11;

pair<int,int> a[N];

void up()
{
    int n;
    cin>>n;
    int p1=2e9,p2=-2e9;
    for (int i=1; i<=n; i++)
    {
        int l,r;
        cin>>l>>r;
        p1=min(p1,r);
        p2=max(p2,l);
    }
    cout<<max(0,p2-p1)<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        up();
    }
}
/**
x*y*z
**/