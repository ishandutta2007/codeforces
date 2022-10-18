#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 4e5 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    if (m<n-1) {cout<<"Impossible\n"; return 0;}
    vector<pair<int,int> > v;
    for (int i=1; i<=n; i++)
    for (int j=i+1; j<=n; j++)
    {
        if (m==0) break;
        if (__gcd(i,j)==1) {m--; v.pb(mp(i,j));}
    }
    if (m!=0) {cout<<"Impossible\n"; return 0;}
    cout<<"Possible\n";
    for (int i=0; i<v.size(); i++)
        cout<<v[i].ff<<" "<<v[i].ss<<"\n";
}