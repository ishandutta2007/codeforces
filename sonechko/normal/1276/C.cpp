#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

map<int,int> mt;
int d[N],kol[N];
int ks[N];
int res[N];
int c;

int num(pair<int,int> pos, int x, int y)
{
    return (pos.ff-1)*y+pos.ss;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        if (mt[x]==0) {c++; mt[x]=c; d[c]=x;}
        kol[mt[x]]++;
    }
    for (int i=1; i<=c; i++)
        ks[kol[i]]++;
    int sum=0,kk=c,ans=0,xx=0,yy=0;
    for (int x=1; x<=n; x++)
    {
        sum+=x*ks[x];
        kk-=ks[x];
        int kol=sum+kk*x;
        int y=kol/x;
        if (x*y>ans&&y>=x)
        {
            ans=x*y;
            xx=x;
            yy=y;
        }
    }
    cout<<ans<<"\n";
    cout<<xx<<" "<<yy<<"\n";
    vector<pair<int,int> > poss;
    for (int j=1; j<=yy; j++)
    {
        int l=1,r=j;
        for (int i=1; i<=xx; i++)
        {
            poss.pb(mp(l,r));
            l++;
            r++;
            if (r==yy+1) r=1;
        }
    }
    reverse(poss.begin(),poss.end());
    vector<pair<int,int> > vs;
    for (int i=1; i<=c; i++)
        vs.pb(mp(kol[i],d[i]));
    sort(vs.begin(),vs.end());
    reverse(vs.begin(),vs.end());
    for (int j=0; j<vs.size(); j++)
        {
            int t=vs[j].ff;
            int p=vs[j].ss;
            t=min(ans,min(t,xx));
            ans-=t;
            while (t>0)
            {
                pair<int,int> r=poss.back();
                poss.pop_back();
                res[num(r,xx,yy)]=p;
                t--;
            }
        }
    for (int i=1; i<=xx; i++)
    {
        for (int j=1; j<=yy; j++)
            cout<<res[num(mp(i,j),xx,yy)]<<" ";
        cout<<"\n";
    }

}

/**
x*y (x<=y)
kol<=x
**/