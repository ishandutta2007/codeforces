#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 700 + 11;

int a[N];
int use[N][N][2];

bool good(int l, int r, int x)
{
    if (l>r) return 1;
    if (use[l][r][x]==1) return 1;
    if (use[l][r][x]==2) return 0;
    for (int c=l; c<=r; c++)
    {
        int d=0;
        if (x==0&&__gcd(a[l-1],a[c])==1) d=1;
        if (x==1&&__gcd(a[r+1],a[c])==1) d=1;
        if (d==0&&good(l,c-1,1)&&good(c+1,r,0)) {use[l][r][x]=1; return 1;}
    }
    use[l][r][x]=2;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    if (good(1,n,1)) cout<<"Yes\n"; else cout<<"No\n";
}