#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair

const int N = 4e5 + 11;

int kol;
int dep[N];
int pred[21][N];
ll sum[21][N],b[N];

void update(int l, ll rr)
{
    kol++;
    b[kol]=rr;
    for (int d=20; d>=0; d--)
        if (pred[d][l]!=0&&b[pred[d][l]]<rr) l=pred[d][l];
    if (b[l]<rr) l=pred[0][l];
    if (l!=0) dep[kol]=dep[l]+1;
    pred[0][kol]=l;
    sum[0][kol]=b[l];
    for (int d=1; d<=20; d++)
    {
        pred[d][kol]=pred[d-1][pred[d-1][kol]];
        sum[d][kol]=sum[d-1][pred[d-1][kol]]+sum[d-1][kol];
    }
}
int ress(int l, ll x)
{
    int r=l;
    if (x<b[l]) return 0;
    x-=b[l];
    for (int d=20; d>=0; d--)
    {
        if (pred[d][l]!=0&&x>=sum[d][l])
        {
            x-=sum[d][l];
            l=pred[d][l];
        }
    }
    return dep[r]-dep[l]+1;
}


int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    kol=1;
    int l=1;
    ll last=0;
    for (int i=1; i<=q; i++)
    {
        int type;
        ll p,t;
        cin>>type>>p>>t;
        ll R=(p^last);
        ll W=(t^last);
        if (type==1) update(R,W); else
        {
            int d=ress(R,W);
            cout<<d<<"\n";
            last=d;
        }
    }
}