#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 3e5 + 11;

ll d[N];

ll get2(int x, int y, int z)
{
    cout<<"2 "<<x<<" "<<y<<" "<<z<<endl;
    ll c;
    cin>>c;
    return c;
}

ll get1(int x, int y, int z)
{
    cout<<"1 "<<x<<" "<<y<<" "<<z<<endl;
    ll c;
    cin>>c;
    return c;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;

    int p1=1,p2=2;
    for (int i=3; i<=n; i++)
        if (get2(1,p2,i)==-1) p2=i;
    if (n==3)
    {
        cout<<0<<" "<<p1<<" "<<p2<<" "<<1+2+3-p1-p2<<endl;
        return 0;
    }
    vector<pair<ll,int> > vv;
    for (int i=1; i<=n; i++)
        if (i!=p1&&i!=p2)
        {
            d[i]=get1(p1,p2,i);
            vv.pb(mp(d[i],i));
        }
    sort(vv.begin(),vv.end());
    reverse(vv.begin(),vv.end());
    vector<int> v1,v2;
    int c=0;
    if (vv[0].ff==vv[1].ff)
    {
        if (get2(p1,vv[0].ss,vv[1].ss)>0) {v1.pb(vv[0].ss); v2.pb(vv[1].ss);}
        else {v1.pb(vv[1].ss); v2.pb(vv[0].ss);}
        c=1;
    } else
    {
        v1.pb(vv[0].ss);
        c=0;
    }
    for (int j=c+1; j<vv.size(); j++)
        if (get2(p1,vv[j].ss,v1.back())>0) v1.pb(vv[j].ss); else v2.pb(vv[j].ss);
    cout<<0<<" "<<p1<<" "<<p2<<" ";
    for (int j=v1.size()-1; j>=0; j--)
        cout<<v1[j]<<" ";
    for (int j=0; j<v2.size(); j++)
        cout<<v2[j]<<" ";
    cout<<endl;
}
/**
(xj-xi)(yj-yi)  (xk-xi)(yk-yi)

(xj-xi)*(yk-yi) > (xk-xi)*(yj-yi)
xj*yk-xj*yi-xi*yk>xk*yj-xk*yi-xi*yj
xj(yk-yi)+xi(yj-yk)+xk(yi-yj) > 0
**/