#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair

const int N = 2e5 + 11;
const ll MOD = 1e9 + 7;

ll a[N];
vector<pair<int,int> > vv;
bool use[N];

void add(int l, int r, int num)
{
    ///cout<<l<<"...."<<r<<endl;
    vv.pb(mp(l,-num));
    vv.pb(mp(r+1,num));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,h,m,k;
    cin>>n>>h>>m>>k;
    int p=m/2-1;
    for (int i=1; i<=n; i++)
    {
        ll x,y;
        cin>>x>>y;
        a[i]=x*1ll*m+y;
        ll l=a[i]+1;
        ll r=a[i]+k-1;
        if (l>r) continue;
        if (r-l>p) add(0,p,i); else
        {
            int x=l%(p+1);
            int y=r%(p+1);
            if (x<=y) add(x,y,i); else
            {
                add(x,p,i);
                add(0,y,i);
            }
        }
    }
    vv.pb(mp(0,0));
    vv.pb(mp(p,0));
    sort(vv.begin(),vv.end());
    int kol=0;
    int ans=n+1,tt=0;
    for (int j=0; j<vv.size(); j++)
    {
        if (vv[j].ff>p) break;
        if (vv[j].ss<0) kol++; else
        if (vv[j].ss>0) kol--;
        if (j==(int)vv.size()-1||vv[j].ff!=vv[j+1].ff)
        {
            if (kol<ans)
            {
                ans=kol;
                tt=vv[j].ff;
            }
        }
    }
    cout<<ans<<" "<<tt<<"\n";
    kol=0;
    for (int j=0; j<vv.size(); j++)
    {
        if (vv[j].ff>p) break;
        if (vv[j].ss<0) {use[-vv[j].ss]=1; kol++;} else
        if (vv[j].ss>0) {kol--; use[vv[j].ss]=0;}
        if (j==(int)vv.size()-1||vv[j].ff!=vv[j+1].ff)
        {
            if (kol==ans)
            {
                for (int i=1; i<=n; i++)
                    if (use[i]) cout<<i<<" ";
                cout<<"\n";
                return 0;
            }
        }
    }
}
/**
1 1 2 1
0 1
**/