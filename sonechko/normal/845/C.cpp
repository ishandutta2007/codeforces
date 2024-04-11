#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;
#define mod %MOD


const int N = 2e5 + 11;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int> > v;
    for (int i=1; i<=n; i++)
    {
        int l,r;
        cin>>l>>r;
        v.pb(mp(l,r));
    }
    sort(v.begin(),v.end());
    int d1=-1,d2=-1;
    for (int i=0; i<v.size(); i++)
    {
        int l=v[i].ff,r=v[i].ss;
        if (l>d1) {d1=r;} else
        if (l>d2) {d2=r;} else {cout<<"NO"<<endl; return 0;}
    }
    cout<<"YES"<<endl;
}