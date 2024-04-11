#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll long long
#define pb push_back
#define mp make_pair

const int N = 2e5 + 11;

void up()
{
    ll a,b,m;
    cin>>a>>b>>m;
    if (a==b)
    {
        cout<<1<<" "<<a<<endl;
        return;
    }
    for (int p=2; p<=50; p++)
    {
        ///cout<<"p: "<<p<<endl;
        ll d=1;
        vector<ll> vv;
        for (int j=1; j<=p-2; j++)
            d*=2ll;
        if (b/a+10<d) break;
        ll c=a*d;
        c+=d;
        if (c>b) break;
        ///cout<<c<<" <= "<<b<<endl;
        for (int k=1; k<p; k++)
        {
            d/=2;
            d=max(d,1ll);
            ///cout<<"? how to add with "<<d<<endl;
            ll t=min(m-1,(b-c)/d);
            ///cout<<"+ "<<t+1<<endl;
            vv.pb(t+1);
            c+=t*d;
        }
        if (c==b)
        {
            cout<<p<<" "<<a<<" ";
            ll s=a;
            for (int j=0; j<vv.size(); j++)
            {
                cout<<s+vv[j]<<" ";
                s+=s+vv[j];
            }
            cout<<endl;
            return;
        }
    }
    cout<<-1<<endl;
    return;
    /**
    x1=a
    x2=a    +t1
    x3=a*2  +t1    +t2
    x4=a*4  +t1*2  +t2   +t3
    x5=a*8  +t1*4  +t2*2 +t3 +t4
    t1, t2, t3, t4, t5 <=m


    5
    a*
    **/
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    for (int j=1; j<=q; j++)
        up();
}