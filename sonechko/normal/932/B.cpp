#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair

const int N = 1e6 + 11;

int f(int l)
{
    int ts=1;
    while (l>0)
    {
        if (l%10!=0) ts*=l%10;
        l/=10;
    }
    return ts;
}

int g(int l)
{
    if (l<10) return l;
    return g(f(l));
}

int a[N],b[N][10];

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    for (int i=1; i<=1000000; i++)
    {
        a[i]=g(i);
        for (int p=1; p<=9; p++)
            if (a[i]==p) b[i][p]=b[i-1][p]+1;
            else b[i][p]=b[i-1][p];
    }
    for (int i=1; i<=q; i++)
    {
        int l,r,k;
        cin>>l>>r>>k;
        cout<<b[r][k]-b[l-1][k]<<"\n";
    }
}