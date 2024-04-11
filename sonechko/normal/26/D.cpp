#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define ld long double

const int N = 2e5 + 11;

int kk[N];

void up(int x, int p)
{
    for (int i=2; i<=x; i++)
    {
        int n=i;
        int d=2;
        while (d*d<=n)
        {
            while (n%d==0)
            {
                kk[d]+=p;
                n/=d;
            }
            d++;
        }
        if (n>1) kk[n]+=p;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    if (k+n<m) {cout<<0<<endl; return 0;}
    if (k>=m) {cout<<1<<endl; return 0;}
    up(n,1);
    up(m,1);
    up(m-k-1,-1);
    up(n+k+1,-1);
    ld c=1;
    for (int i=1; i<=n+m+k; i++)
    {
        while (kk[i]>0)
        {
            kk[i]--;
            c*=(ld)i;
        }
        while (kk[i]<0)
        {
            kk[i]++;
            c/=(ld)i;
        }
    }
    cout.precision(10);
    cout<<fixed;
    cout<<1-c<<endl;
}