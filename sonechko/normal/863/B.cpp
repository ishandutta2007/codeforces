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
int a[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=2*n; i++)
        cin>>a[i];
    int res=1e9;
    for (int i=1; i<=2*n; i++)
    for (int j=i+1; j<=2*n; j++)
    {
        vector<int> v;
        for (int k=1; k<=2*n; k++)
            if (k!=i&&k!=j) v.pb(a[k]);
        sort(v.begin(),v.end());
        int ans=0;
        for (int i=0; i<v.size(); i+=2)
            ans+=v[i+1]-v[i];
        res=min(res,ans);
    }
    cout<<res<<endl;
}