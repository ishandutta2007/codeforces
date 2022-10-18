#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int N = 1e5 + 11;
const int MOD = 666013;
#define mod %MOD

int kol=0;
vector<pair<int,pair<int,int> > > vv;
int a1[N],a2[N],b1[N],b2[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>b1[i];
    for (int i=1; i<=n; i++)
        cin>>a1[i];
    for (int i=1; i<=n; i++)
        cin>>a2[i];
    for (int i=1; i<=n; i++)
        cin>>b2[i];
    while (1==1)
    {
        for (int i=1; i<=n; i++)
        {
            if (b1[i]!=0&&a1[i]==b1[i])
            {
                kol++;
                vv.pb(mp(a1[i],mp(1,i)));
                b1[i]=0;
                a1[i]=0;
            }
            if (b2[i]!=0&&a2[i]==b2[i])
            {
                kol++;
                vv.pb(mp(a2[i],mp(4,i)));
                b2[i]=0;
                a2[i]=0;
            }
        }
        if (kol==m) break;
        if (m-kol==n*2) {cout<<-1<<endl; return 0;}
        vector<pair<int,pair<int,int> > > v;
        for (int i=1; i<=n; i++)
            v.pb(mp(a1[i],mp(2,i)));
        for (int i=n; i>=1; i--)
            v.pb(mp(a2[i],mp(3,i)));
        int t=0;
        for (int j=0; j<v.size(); j++)
            if (v[j].ff==0) t=j;
        for (int j=t+1; j<v.size(); j++)
            if (v[j].ff!=0) vv.pb(mp(v[j].ff,v[j-1].ss));
        if (v[0].ff!=0) vv.pb(mp(v[0].ff,v.back().ss));
        for (int j=1; j<=t; j++)
            if (v[j].ff!=0) vv.pb(mp(v[j].ff,v[j-1].ss));
        int c=a1[1];
        for (int i=2; i<=n; i++)
            a1[i-1]=a1[i];
        a1[n]=a2[n];
        for (int i=n-1; i>=1; i--)
            a2[i+1]=a2[i];
        a2[1]=c;
    }
    cout<<vv.size()<<endl;
    for (int i=0; i<vv.size(); i++)
        cout<<vv[i].ff<<" "<<vv[i].ss.ff<<" "<<vv[i].ss.ss<<endl;
}