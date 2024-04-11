#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define ss second

const int N = 1e6 + 11;

char a[N];
int s[N];
int n,m;
int t[N];

int num(int l, int r)
{
    if (l<1||r<1) return 0;
    return (l-1)*m+r;
}

int sum(int l1, int r1, int l2, int r2)
{
    l1=max(l1,1);
    r1=max(r1,1);
    return s[num(l2,r2)]-s[num(l1-1,r2)]-s[num(l2,r1-1)]+s[num(l1-1,r1-1)];
}

int sum2(int l1, int r1, int l2, int r2)
{
    l1=max(l1,1);
    r1=max(r1,1);
    return t[num(l2,r2)]-t[num(l1-1,r2)]-t[num(l2,r1-1)]+t[num(l1-1,r1-1)];
}

bool good(int l1, int r1, int l2, int r2)
{
    if (l1<1||r1<1||l2>n||r2>m) return false;
    int c=sum(l1,r1,l2,r2);
    if (c==(l2-l1+1)*(r2-r1+1)) return true;
    return false;
}

bool good(int x)
{
    x*=2;
    x++;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    {
        int c=0;
        if (good(i,j,i+x-1,j+x-1)) c=1;
        t[num(i,j)]=t[num(i-1,j)]+t[num(i,j-1)]-t[num(i-1,j-1)]+c;
    }
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
        if (a[num(i,j)]==1)
    {
        if (sum2(i-x+1,j-x+1,i,j)==0) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    {
        char c;
        cin>>c;
        if (c=='X') a[num(i,j)]=1;
        s[num(i,j)]=s[num(i-1,j)]+s[num(i,j-1)]-s[num(i-1,j-1)]+a[num(i,j)];
    }
    int l=0,r=min(n,m);
    while (r-l>1)
    {
        int mid=(l+r)/2;
        if (good(mid)) l=mid; else r=mid;
    }
    int x=0;
    if (good(r)) x=r; else x=l;
    cout<<x<<"\n";
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
            if (good(i-x,j-x,i+x,j+x)) cout<<"X"; else cout<<".";
        cout<<"\n";
    }

}
/**
x*y*z
**/