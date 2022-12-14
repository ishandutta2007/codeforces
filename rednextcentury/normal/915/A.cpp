#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    int ret=1e9;
    for (int i=1;i<=n;i++) {
        int x;
        cin>>x;
        if (k%x==0)ret=min(ret,k/x);
    }
    cout<<ret<<endl;
}