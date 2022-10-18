#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 5e5 + 11;

int use[N],pr[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    pr[1]=1;
    for (int i=2; i<=n; i++)
        if (pr[i]==0)
    {
        pr[i]=1;
        for (ll j=i*1ll*i; j<=n; j+=i)
            if (pr[j]==0) pr[j]=j/i;
    }
    use[1]=1;
    for (int i=2; i<=n; i++)
        if (pr[i]==1) {use[i]=1; cout<<1<<" ";}
    for (int j=2; j<=n; j++)
    {
        for (int t=j; t<=min(1ll*n,j*1ll*j); t+=j)
            if (use[t]==0)
        {
            int c=pr[t];
            if (c<=j) {use[t]=1; cout<<j<<" ";}
        }
    }
}
/**

20
2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 1 1 1 1 1 1 1 2  3  3  4  5  5  6  7  8  9  10

1 1 1 1 1 1 1 1 1 2 3 3 4 5 5 5 6 7 7 8 9 10 11 12

**/