#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair

const int N = 1e5 + 11;
int a[N];
int main() {
    int n,k,p;
    cin>>n>>k>>p;
    for (int i=1; i<=n; i++)
    cin>>a[i];
    vector<int> v1;
    for (int i=1; i<=k; i++)
    {
       int l;
       cin>>l;
       v1.pb(l);
    }
    sort(v1.begin(),v1.end());
    sort(a+1,a+n+1);
    int ans=INT_MAX;
    for (int i=0; i<v1.size(); i++)
        if (i+n-1<v1.size())
    {
        vector<int> v;
        int l=0;
        for (int ij=i; ij<=i+n-1; ij++)
            v.pb(v1[ij]);
        int k=0,aans=0;
        for (int ij=1; ij<=n; ij++)
        {
            int r=a[ij];
            aans=max(aans,abs(v[k]-r)+abs(v[k]-p));
            k++;
        }
        ans=min(ans,aans);
    }
    cout<<ans<<endl;
}