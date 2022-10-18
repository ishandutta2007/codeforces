#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ss second
#define ff first
#define endl "\n"
#define ld long double
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;
#define mod %MOD


const int N = 3e5 + 11;
int nx[N],ans[N];
int nnx(int l)
{
    if (nx[l]==l) return l;
    nx[l]=nnx(nx[l]);
    return nx[l];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        nx[i]=i;
    nx[n+1]=n+1;
    for (int i=1; i<=m; i++)
    {
        int l,r,k;
        cin>>l>>r>>k;
        int x=nnx(l);
        while (x<=r)
        {
            if (x==k) x++; else {nx[x]=x+1; ans[x]=k;}
            x=nnx(x);
        }
    }
    for (int i=1; i<=n; i++)
    cout<<ans[i]<<" ";
    cout<<endl;
}