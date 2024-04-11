#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

const int N = 2e5 + 11;

int s[N],d[N],c[N];
int pp[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<pair<int,int> > vv;
    for (int i=1; i<=m; i++)
    {
        cin>>s[i]>>d[i]>>c[i];
        if (d[i]-s[i]<c[i]) {cout<<-1<<endl; return 0;}
        pp[d[i]]=m+1;
        vv.pb(mp(d[i],i));
    }
    sort(vv.begin(),vv.end());
    for (int ii=0; ii<vv.size(); ii++)
    {
        int i=vv[ii].ss;
        for (int j=s[i]; j<=d[i]; j++)
        {
            if (c[i]==0) continue;
            if (pp[j]!=0) continue;
            c[i]--;
            pp[j]=i;
        }
        if (c[i]!=0) {cout<<"-1"<<endl; return 0;}
    }
    for (int i=1; i<=n; i++)
        cout<<pp[i]<<" ";
    cout<<endl;
}