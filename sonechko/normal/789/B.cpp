#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define ld long double
const int N = 2e5 + 11;
int a[N];
map<int,bool> use;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll k1,q,l,m;
    cin>>k1>>q>>l>>m;
    if (k1==0)
    {
        for (int j=1; j<=m; j++)
        {
            ll k;
            cin>>k;
            if (k==0) {cout<<0<<endl; return 0;}
        }
        cout<<"inf"<<endl; return 0;
    }
    if (q==0)
    {
        ll ans1=0,ans2=0;
        if (abs(k1)>l) {cout<<0<<endl; return 0;}
        for (int j=1; j<=m; j++)
        {
            ll k;
            cin>>k;
            if (k==0) ans1=1;
            if (k==k1) ans2=1;
        }
        if (ans1==1&&ans2==1) cout<<0<<endl; else
        if (ans1==1) cout<<1<<endl; else cout<<"inf"<<endl;
        return 0;
    }
    if (q==1||q==-1)
    {
        if (abs(k1)>l) {cout<<0<<endl; return 0;}
        int ans1=0,ans2=0;
        for (int i=1; i<=m; i++)
        {
            int p;
            cin>>p;
            if (q==1&&p==k1) {cout<<0<<endl; return 0;}
            if (q==-1&&p==k1) {ans1=k1;}
            if (q==-1&&p==-k1) {ans2=k1;}
        }
        if (ans1==0||ans2==0)
        cout<<"inf"<<endl; else cout<<0<<endl;
        return 0;
    }
    for (int i=1; i<=m; i++)
    {
        int lr;
        cin>>lr;
        use[lr]=1;
    }
    ll cc=k1;
    ll ans=0;
    while (abs(cc)<=l)
    {
        ans++;
        if (use[cc]==1) ans--;
        cc*=q;
    }
    cout<<ans<<endl;
}