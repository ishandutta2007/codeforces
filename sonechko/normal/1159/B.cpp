#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 3e5 + 11;

int a[N],use[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int> > vv;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        vv.pb(mp(a[i],i));
    }
    int ans=2e9;
    sort(vv.begin(),vv.end());
    int fir=1,sec=n;
    for (int i=0; i<vv.size(); i++)
    {
        int pos=vv[i].ss;
        if (fir!=pos) ans=min(ans,vv[i].ff/(pos-fir));
        if (sec!=pos) ans=min(ans,vv[i].ff/(sec-pos));
        use[pos]=1;
        while (use[fir]==1)
            fir++;
        while (use[sec]==1)
            sec--;
    }
    cout<<ans<<endl;
}
/**
min

    ai
----------- ai<aj
    |i-j|
**/