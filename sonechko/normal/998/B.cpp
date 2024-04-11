#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long

const int N = 1e6 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,b;
    cin>>n>>b;
    int k=0;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    vector<int> vv;
    for (int i=1; i<=n; i++)
    {
        if (a[i]%2==0) k++; else k--;
        if (k==0&&i!=n) vv.pb(abs(a[i]-a[i+1]));
    }
    int ans=0;
    sort(vv.begin(),vv.end());
    for (int j=0; j<vv.size(); j++)
    if (vv[j]<=b) {ans++; b-=vv[j];}
    cout<<ans<<endl;
}