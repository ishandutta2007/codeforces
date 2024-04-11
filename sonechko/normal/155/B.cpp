#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N = 1e3 + 11;
int a[N];
int main()
{
    int n;
    cin>>n;
    int ks=1;
    int ans=0;
    vector<int> v;
    for (int i=1; i<=n; i++)
    {
        int l,r;
        cin>>l>>r;
        if (r>0) {ks+=r-1; ans+=l;} else v.pb(-l);
    }
    sort(v.begin(),v.end());
    for (int i=0; i<min((int)v.size(),ks); i++)
        ans+=-v[i];
    cout<<ans<<endl;
}