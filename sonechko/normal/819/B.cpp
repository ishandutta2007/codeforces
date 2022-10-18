#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define ss second
#define ld long double
#define pb push_back
#define ff first
const int N = 1e6 + 11;
const int M = 1e9;
ll b[N];
vector<pair<int,pair<int, int> > > v1,v2;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        {
            int l;
            cin>>l;
            if (l>i)
            {
                v2.pb(mp(1,mp(l-i+1,l-i)));
                //cout<<"- "<<1<<" "<<l-i+1<<" "<<l-i<<endl;
                int xx=l-i+1;
                if (xx+1<=n) v1.pb(mp(xx+1,mp(xx+n-l,1)));
                //cout<<"+ "<<xx+1<<" "<<xx+n-l<<" "<<1<<endl;
                xx+=n-l;
                if (xx+1<=n) v2.pb(mp(xx+1,mp(n,l-1)));
                //cout<<"- "<<xx+1<<" "<<n<<" "<<l-1<<endl;
            } else
            if (l<i)
            {
                v1.pb(mp(1,mp(n-i+1,i-l)));
                //cout<<"+ "<<1<<" "<<n-i+1<<" "<<i-l<<endl;
                int xx=n-i+1;
                if (xx+1<=n) v2.pb(mp(xx+1,mp(xx+l,l-1)));
                //cout<<"- "<<xx+1<<" "<<xx+l<<" "<<l-1<<endl;
                xx+=l;
                if (xx+1<=n) v1.pb(mp(xx+1,mp(n,1)));
                //cout<<"+ "<<xx+1<<" "<<n<<" "<<1<<endl;
            } else
            {
                v1.pb(mp(1,mp(n-l+1,0)));
                //cout<<"+ "<<1<<" "<<n-l+1<<" "<<0<<endl;
                if (n-l+2<=n) v2.pb(mp(n-l+2,mp(n,l-1)));
                //cout<<"- "<<n-l+2<<" "<<n<<" "<<l-1<<endl;
            }
            //cout<<endl;
        }
    vector<pair<int,int> > vv;
    for (int i=0; i<v1.size(); i++)
    {
        vv.pb(mp(v1[i].ff,-(i+1)));
        vv.pb(mp(v1[i].ss.ff,i+1));
    }
    sort(vv.begin(),vv.end());
    ll sum=0,kol=0;
    int p=0;
    ll ans=LONG_LONG_MAX,res=0;
    for (int i=1; i<=n; i++)
    {
        while (p<vv.size()&&vv[p].ff==i&&vv[p].ss<0)
        {
            int num=abs(vv[p].ss)-1;
            sum+=v1[num].ss.ss;
            kol++;
            p++;
        }
        b[i]=sum;
        while (p<vv.size()&&vv[p].ff==i)
        {
            int num=abs(vv[p].ss)-1;
            sum-=v1[num].ss.ss+(v1[num].ss.ff-v1[num].ff);
            kol--;
            p++;
        }
        sum+=kol;
    }












    vv.clear();
    for (int i=0; i<v2.size(); i++)
    {
        vv.pb(mp(v2[i].ff,-(i+1)));
        vv.pb(mp(v2[i].ss.ff,i+1));
    }
    sort(vv.begin(),vv.end());
    sum=0;
    kol=0;
    p=0;
    for (int i=1; i<=n; i++)
    {
        while (p<vv.size()&&vv[p].ff==i&&vv[p].ss<0)
        {
            int num=abs(vv[p].ss)-1;
            sum+=v2[num].ss.ss;
            kol++;
            p++;
        }
        b[i]+=sum;
        if (b[i]<ans) {ans=b[i]; res=i-1;}
        while (p<vv.size()&&vv[p].ff==i)
        {
            int num=abs(vv[p].ss)-1;
            sum-=v2[num].ss.ss-(v2[num].ss.ff-v2[num].ff);
            kol--;
            p++;
        }
        sum-=kol;
    }
    cout<<ans<<" "<<res<<endl;
}