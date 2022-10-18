#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define mp make_pair
#define ff first
#define ss second

const int N = 5e5 + 11;

int nx[N],pr[N],gl[N],p1[N],p2[N];

int glava(int l)
{
    if (gl[l]==l) return l;
    return gl[l]=glava(gl[l]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        gl[i]=i;
        p1[i]=i;
        p2[i]=i;
    }
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        int x=glava(l);
        int y=glava(r);
        nx[p2[x]]=p1[y];
        pr[p1[y]]=p2[x];
        gl[x]=y;
        p1[y]=p1[x];
    }
    int d=0;
    for (int i=1; i<=n; i++)
        if (pr[i]==0) {d=i;}
    for (int i=1; i<=n; i++)
    {
        cout<<d<<" ";
        d=nx[d];
    }
    cout<<endl;
}