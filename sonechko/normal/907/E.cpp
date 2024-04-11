#include <bits/stdc++.h>
using namespace std;
#define pb push_back

const int N = 1e5 + 11;

int g[N];

bool good[5000000];

void gg(int l)
{
    for (int j=1; j<=22; j++)
        if (l&(1<<(j-1))) cout<<1; else cout<<0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        g[l]^=(1<<(r-1));
        g[r]^=(1<<(l-1));
    }
    if (m==n*(n-1)/2) {cout<<0<<endl; return 0;}
    int res=n,ss=0;
    for (int mask=1; mask<=(1<<n)-1; mask++)
    {
        int kol=0;
        for (int x=1; x<=n; x++)
            if (mask&(1<<(x-1))) kol++;
        if (kol>res) continue;
        if (kol==1) good[mask]=1;
        if (good[mask]==0) continue;
        for (int p=1; p<=n; p++)
            if (g[p]&mask) good[mask^(1<<(p-1))]=1;


        int ps=0;
        for (int i=1; i<=n; i++)
            if ((!(g[i]&mask))) ps++;
        if (kol==1) ps--;
        if (ps>0) continue;
        res=kol;
        ss=mask;
    }
    cout<<res<<endl;
    for (int i=1; i<=n; i++)
        if (ss&(1<<(i-1))) cout<<i<<" ";
    cout<<endl;
}
/**
22 31
1 10
1 17
2 3
2 6
2 15
2 19
2 21
3 6
3 15
3 19
3 21
4 22
5 11
5 13
6 15
6 19
6 21
7 8
7 21
8 14
9 16
9 20
10 12
11 14
12 22
13 16
15 19
15 21
17 18
18 20
19 21
**/