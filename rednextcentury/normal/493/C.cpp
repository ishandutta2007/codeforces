#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1000000009;
int a[1000000];
int b[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n;
    vector<int> pos;
    for (int i=1;i<=n;i++)cin>>a[i],pos.push_back(a[i]),pos.push_back(a[i]-1),pos.push_back(a[i]+1);
    cin>>m;
    for (int i=1;i<=m;i++)cin>>b[i],pos.push_back(b[i]),pos.push_back(b[i]-1),pos.push_back(b[i]+1);
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    sort(pos.begin(),pos.end());
    int l=0,r=0;
    ll A = 3*n;
    ll B = 3*m;
    ll ret=-1e12;
    ll AA=0,BB=0;
    if (A-B>ret)ret=A-B,AA=A,BB=B;
    for (auto X:pos){
        while(l+1<=n && a[l+1]<=X)A--,l++;
        while(r+1<=m && b[r+1]<=X)B--,r++;
        if (A-B>ret)ret=A-B,AA=A,BB=B;
    }
    cout<<AA<<":"<<BB<<endl;
}