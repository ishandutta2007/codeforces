#include<bits/stdc++.h>
using namespace std;
#define ll long long
int work[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int> > a(n, vector<int>(m));
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin>>a[i][j];
            a[i][j]-=j+1;
        }
    }
    ll ans=0;
    for (int j=0;j<m;j++) {
        for (int i=0;i<n;i++) {
            int v = a[i][j];
            if (v<0)continue;
            if (v%m!=0)continue;
            v/=m;
if (v>(n-1))continue;
            int loc = ((i-v+n)%n)+n;
loc%=n;
            work[loc]++;
        }
        int ret=1e9;
        for (int i=0;i<n;i++)
        {
            int cur = n - work[i] + i;
            work[i]=0;
            ret=min(ret,cur);
        }
        ans+=ret;
    }
    cout<<ans<<endl;
}