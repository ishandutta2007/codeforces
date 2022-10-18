#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define y1 skfn

const int N = 1000 + 11;
const int MOD = 1e9 + 7;
#define mod %MOD

int l1,r1,l2,r2,l3,r3,n;
bool use[N][N];

void dfs(int l, int r)
{
    if (l<1||r<1||l>n||r>n) return;
    if (use[l][r]==1) return;
    use[l][r]=1;
    if (l==l1) return;
    if (r==r1) return;
    if (l+r==l1+r1) return;
    if (l-r==l1-r1) return;
    if (l==l3&&r==r3) {cout<<"YES"<<endl; exit(0);}
    dfs(l-1,r);
    dfs(l+1,r);
    dfs(l,r-1);
    dfs(l,r+1);
    dfs(l-1,r-1);
    dfs(l-1,r+1);
    dfs(l+1,r-1);
    dfs(l+1,r+1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>l1>>r1>>l2>>r2>>l3>>r3;
    dfs(l2,r2);
    cout<<"NO"<<endl;
}