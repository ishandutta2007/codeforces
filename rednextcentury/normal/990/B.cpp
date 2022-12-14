#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000000];
bool vis[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    set<int> s;
    for (int i=0;i<n;i++) cin>>a[i],s.insert(a[i]);
    sort(a,a+n);
    int ret=n;
    for (int i=0;i<n;i++) {
        auto p = s.upper_bound(a[i]);
        if (p==s.end())continue;
        if (*p - a[i] <= k)ret--;
    }
    cout<<ret<<endl;
}