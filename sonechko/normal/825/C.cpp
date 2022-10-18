#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 11;
int a[N];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        int x=(a[i]+1)/2;
            while (m<x)
            {
                ans++;
                m*=2;
            }
            m=max(m,a[i]);
    }
    cout<<ans<<endl;
}