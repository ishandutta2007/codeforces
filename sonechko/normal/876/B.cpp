#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define ss second
#define ff first
const int MOD = 1000000007;
#define mod %MOD
#define pb push_back
#define ld long double
const int N = 1e6 + 11;
const int MAX = 1e8;

vector<int> v[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k,m;
    cin>>n>>k>>m;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        v[l%m].pb(l);
    }
    for (int i=0; i<m; i++)
        if (v[i].size()>=k)
    {
        cout<<"Yes"<<endl;
        for (int ii=0; ii<k; ii++)
            cout<<v[i][ii]<<" ";
        cout<<endl;
        return 0;
    }
    cout<<"No"<<endl;
}