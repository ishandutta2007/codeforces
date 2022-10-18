#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long

const int N = 2e5 + 11;

bool good(int l, int r, int k, int kk)
{
    if (l<kk||r<kk) return 0;
    l-=kk;
    r-=kk;
    if (l+r+k>=kk) return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    for (int i=1; i<=q; i++)
    {
        int l,r,k;
        cin>>l>>r>>k;
        int l1=0,r1=1e8;
        while (r1-l1>1)
        {
            int mid=(l1+r1)/2;
            if (good(l,r,k,mid)) l1=mid; else r1=mid;
        }
        if (good(l,r,k,r1)) cout<<r1<<"\n"; else cout<<l1<<"\n";
    }
}
/**
B.B.B.......
..WBW.......
BW.WB.......
.B.B........
B.B.........
............
............
............
............
............
............
............



**/