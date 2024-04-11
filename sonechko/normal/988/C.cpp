#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;
const int MOD = 1e9 + 7;

int a[N];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k;
    cin>>k;
    vector<pair<int,pair<int, int> > > v;
    for (int i=1; i<=k; i++)
    {
        int n;
        cin>>n;
        int ss=0;
        for (int j=1; j<=n; j++)
        {
            cin>>a[j];
            ss+=a[j];
        }
        for (int j=1; j<=n; j++)
        v.pb(mp(ss-a[j],mp(i,j)));
    }
    sort(v.begin(),v.end());
    for (int j=1; j<v.size(); j++)
        if (v[j].ff==v[j-1].ff&&v[j].ss.ff!=v[j-1].ss.ff)
    {
        cout<<"YES"<<endl;
        cout<<v[j].ss.ff<<" "<<v[j].ss.ss<<endl;
        cout<<v[j-1].ss.ff<<" "<<v[j-1].ss.ss<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
}