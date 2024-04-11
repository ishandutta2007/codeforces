#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

const int N = 3e5 + 11;

void up()
{
    int n;
    cin>>n;
    vector<pair<int,pair<int,int> > > vv;
    for (int i=1; i<=n; i++)
    {
        int x,y;
        cin>>x>>y;
        vv.pb(mp(x+y,mp(x,y)));
    }
    sort(vv.begin(),vv.end());
    string ans="";
    int x=0,y=0;
    for (int j=0; j<vv.size(); j++)
    {
        int xx=vv[j].ss.ff,yy=vv[j].ss.ss;
        if (x>xx||y>yy) {cout<<"NO\n"; return;}
        while (x<xx)
        {
            x++;
            ans+="R";
        }
        while (y<yy)
        {
            y++;
            ans+="U";
        }
    }
    cout<<"YES\n";
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
        up();
}