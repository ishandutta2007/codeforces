#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pai
#define ff first
#define ss second
const ll N = 1e6 + 11;
int a[N],d,n,m;
void dfs(int l, int r, int k)
{
    if (l==r-1)
    {
        a[l]=k;
        return;
    }
    if (m==0)
    {
        if (k==0) return;
        a[r-1]=k;
        return;
    }
    m-=2;
    int mid=(l+r)/2;
    if (k==0) {k=d; d--;}
    dfs(l,mid,k);
    dfs(mid,r,0);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    m--;
    if (m%2==1) {cout<<-1<<endl; return 0;}
    d=n;
    dfs(0,n,0);
    if (m>0) {cout<<-1<<endl; return 0;}
    int ks=1;
    for (int i=0; i<n; i++)
        if (a[i]!=0) cout<<a[i]<<" "; else
    {
        cout<<ks<<" ";
        ks++;
    }
}