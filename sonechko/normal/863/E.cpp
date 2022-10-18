#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;
#define mod %MOD


const int N = 1200000 + 11;
map<int,int> mt;
int a[N],b[N],c[N];
int w[5*N];
void build(int i, int l, int r)
{
    if (l==r) {w[i]=c[l]; return;}
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    w[i]=min(w[i*2],w[i*2+1]);
}
int mini(int i, int l, int r, int tl, int tr)
{
    if (tl<=l&&r<=tr) return w[i];
    if (tl>r||tr<l) return 5;
    int mid=(l+r)/2;
    return min(mini(i*2,l,mid,tl,tr),mini(i*2+1,mid+1,r,tl,tr));
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<int> v;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i]>>b[i];
        v.pb(a[i]);
        v.pb(b[i]);
        v.pb(a[i]-1);
        v.pb(a[i]+1);
        v.pb(b[i]-1);
        v.pb(b[i]+1);
    }
    sort(v.begin(),v.end());
    int kol=0;
    for (int i=0; i<v.size(); i++)
        if (i==0||v[i]!=v[i-1])
    {
        kol++;
        mt[v[i]]=kol;
    }
    for (int i=1; i<=n; i++)
    {
        a[i]=mt[a[i]];
        b[i]=mt[b[i]];
        c[a[i]]++;
        c[b[i]+1]--;
    }
    for (int i=1; i<=kol; i++)
    {
        c[i]=c[i-1]+c[i];
    }
    build(1,1,kol);
    for (int i=1; i<=n; i++)
        if (mini(1,1,kol,a[i],b[i])>=2)
    {
        cout<<i<<endl;
        return 0;
    }
    cout<<-1<<endl;
}