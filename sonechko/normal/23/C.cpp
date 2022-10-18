#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ll long long

const int N = 2e5 + 11;

pair<int,pair<int,int> > a[N];

void up()
{
    int n;
    cin>>n;
    for (int i=1; i<=2*n-1; i++)
    {
        cin>>a[i].ff>>a[i].ss.ff;
        a[i].ss.ss=i;
    }
    sort(a+1,a+2*n);
    ll s1=0,s2=0;
    for (int i=1; i<=2*n-1; i++)
    {
        s1+=1ll*a[i].ss.ff;
        if (i%2==1) s2+=1ll*a[i].ss.ff;
    }
    if (s2*2>=s1)
    {
        cout<<"YES\n";
        for (int i=1; i<=2*n-1; i+=2)
            cout<<a[i].ss.ss<<" ";
        cout<<"\n";
        return;
    }
    s1=0;
    s2=0;
    for (int i=1; i<=2*n-1; i++)
    {
        s1+=1ll*a[i].ss.ff;
        if (i%2==0||i==2*n-1) s2+=1ll*a[i].ss.ff;
    }
    if (s2*2>=s1)
    {
        cout<<"YES\n";
        for (int i=1; i<=2*n-1; i++)
            if (i%2==0||i==2*n-1) cout<<a[i].ss.ss<<" ";
        cout<<"\n";
        return;
    }
    cout<<"NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
        up();
}

/**

1  2  2  6  6
x1 x2 x3 x4 x5

**/