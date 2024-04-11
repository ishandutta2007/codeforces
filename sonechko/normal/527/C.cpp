#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb push_back

const int N = 3e5 + 11;

vector<pair<char,int> > vv;
vector<ll> p;
int use1[N],use2[N],glava1[N],glava2[N],sz1[N],sz2[N];
int gl1(int l)
{
    if (l==glava1[l]) return l;
    glava1[l]=gl1(glava1[l]);
    return glava1[l];
}
int gl2(int l)
{
    if (l==glava2[l]) return l;
    glava2[l]=gl2(glava2[l]);
    return glava2[l];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m,n,k;
    cin>>m>>n>>k;
    for (int i=1; i<=k; i++)
    {
        char ch;
        cin>>ch;
        int l;
        cin>>l;
        if (ch=='H') use1[l]=1; else use2[l]=1;
        vv.pb(mp(ch,l));
    }
    int x=1;
    int res1=0,res2=0;
    for (int i=1; i<=n; i++)
    {
        glava1[i]=x;
        sz1[x]++;
        res1=max(res1,sz1[x]);
        if (use1[i]==1) x=i+1;
    }
    x=1;
    for (int i=1; i<=m; i++)
    {
        glava2[i]=x;
        sz2[x]++;
        res2=max(res2,sz2[x]);
        if (use2[i]==1) x=i+1;
    }
    for (int i=vv.size()-1; i>=0; i--)
    {
        p.pb(res1*1LL*res2);
        if (vv[i].ff=='H')
        {
            int d1=gl1(vv[i].ss);
            int d2=vv[i].ss+1;
            glava1[d2]=d1;
            sz1[d1]+=sz1[d2];
            res1=max(res1,sz1[d1]);
        } else
        {
            int d1=gl2(vv[i].ss);
            int d2=vv[i].ss+1;
            glava2[d2]=d1;
            sz2[d1]+=sz2[d2];
            res2=max(res2,sz2[d1]);
        }
    }
    for (int j=p.size()-1; j>=0; j--)
        cout<<p[j]<<"\n";
}