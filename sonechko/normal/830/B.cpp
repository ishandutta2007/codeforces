#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair

const int N = 1e5 + 11;
int t[N],n,a[N];
int sum(int r)
{
	int res=0;
	for (; r>=0; r=(r&(r+1))-1)
		res+=t[r];
	return res;
}
void inc(int i, int d)
{
	for (; i<=n; i=(i|(i+1)))
		t[i] += d;
}
int sum(int l, int r)
{
	return sum(r)-sum(l-1);
}
int main() {
    cin>>n;
    vector<pair<int,int> > v;
    for (int i=1; i<=n; i++)
        inc(i,1);
    for (int i=1; i<=n; i++)
        {
            cin>>a[i];
            v.pb(mp(a[i],i));
        }
    sort(v.begin(),v.end());
    int l=1;
    v.pb(mp(-1,-1));
    vector<int> vv;
    ll ans=0;
    vv.pb(v[0].ss);
    for (int i=1; i<v.size(); i++)
    {
        if (v[i].ff==v[i-1].ff)
        {
            vv.pb(v[i].ss);
        } else
        {
            int d=0;
            for (int j=0; j<vv.size(); j++)
                if (vv[j]<l) d=vv[j]; else
                if (d==0||d>=l) d=vv[j];
            if (d<l) { ans+=(ll)sum(l,n)+(ll)sum(1,d);} else {ans+=(ll)sum(l,d);}
            for (int j=0; j<vv.size(); j++)
                inc(vv[j],-1);
            vv.clear();
            l=d;
            vv.pb(v[i].ss);
        }
    }
    cout<<ans<<endl;
}