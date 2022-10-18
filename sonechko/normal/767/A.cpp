#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 11;
const long long MOD = 1e9 + 7;
#define mod %MOD
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ss second
#define ff first
#define ll long long
#define mp make_pair
#define endl "\n"
#define pb push_back
#define ld long double
vector<int> v[N];
pair<int,int> a[N];
int main()
{
    sync;
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        a[i]=mp(l,i);
    }
    int k=0;
    sort(a+1,a+n+1);
    for (int i=n; i>=1; i--)
    {
        k=max(k,a[i].ss);
        v[k].pb(a[i].ff);
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<v[i].size(); j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }

}