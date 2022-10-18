#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

vector<pair<int,string> > vv;

void up()
{
    cout<<"YES"<<endl;
    cout<<vv.size()<<endl;
    for (int i=0; i<vv.size(); i++)
        cout<<vv[i].ff<<" "<<vv[i].ss<<endl;
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    int kol=4*n*m-2*n-2*m;
    if (k>kol) return cout<<"NO", 0;
    if (k<=m-1)
    {
        vv.pb(mp(k,"R"));
        up();
    } else
    if (m-1>0)
    {
        vv.pb(mp(m-1,"R"));
        k-=m-1;
    }
    if (k<=m-1)
    {
        vv.pb(mp(k,"L"));
        up();
    } else
    if (m-1>0)
    {
        vv.pb(mp(m-1,"L"));
        k-=m-1;
    }
    for (int j=2; j<=n; j++)
    {

        if (k==1)
        {
            vv.pb(mp(1,"D"));
            up();
        }
        vv.pb(mp(1,"D"));
        k--;



        int t=(m-1)*3;
        if (k<=t)
        {
            int c=k/3;
            if (c>0) vv.pb(mp(c,"RUD"));
            k%=3;
            if (k==0) up();
            vv.pb(mp(1,"R"));
            k--;
            if (k==0) up();
            vv.pb(mp(1,"U"));
            k--;
            up();
        }
        if (m-1>0)
        {
            k-=t;
            vv.pb(mp(m-1,"RUD"));
        }

        if (k<=m-1)
        {
            vv.pb(mp(k,"L"));
            up();
        } else
        if (m-1>0)
        {
            vv.pb(mp(m-1,"L"));
            k-=m-1;
        }
    }

    vv.pb(mp(k,"U"));
    up();
}