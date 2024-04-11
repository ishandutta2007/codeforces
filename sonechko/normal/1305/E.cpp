#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 3e7 + 11;

int sum[N];
int a[N];

int get(int len)
{
    int x=0;
    for (int d=len-2; d>=1; d-=2)
        x+=d;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    if (get(n)<m)
    {
        cout<<"-1";
        return 0;
    }
    a[1]=1;
    int last=0;
    for (int i=2; i<=n; i++)
    {
        int t=a[i-1]+1;
        while (m<sum[t])
            t++;
        a[i]=t;
        m-=sum[t];
        for (int j=1; j<i; j++)
            if (a[j]+a[i]<=30000000) sum[a[j]+a[i]]++;
    }
    if (m!=0) return cout<<"-1", 0;
    for (int i=1; i<=n; i++)
        cout<<a[i]<<" ";
}