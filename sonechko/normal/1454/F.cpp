#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define pb push_back
#define ss second
#define mp make_pair

const int N = 2e5 + 11;

map<int,int> last;
int nx[N],mx_suf[N];
int a[N];
int v[N*4];

int mini(int i, int l, int r, int tl, int tr)
{
    if (tl<=l&&r<=tr) return v[i];
    if (tl>r||l>tr) return 2e9;
    int mid=(l+r)/2;
    return min(mini(i+i,l,mid,tl,tr),mini(i+i+1,mid+1,r,tl,tr));
}

void build(int i, int l, int r)
{
    if (l==r) {v[i]=a[l]; return;}
    int mid=(l+r)/2;
    build(i+i,l,mid);
    build(i+i+1,mid+1,r);
    v[i]=min(v[i+i],v[i+i+1]);
}

void up()
{
    int n;
    cin>>n;
    last.clear();
    for (int i=1; i<=n; i++)
        nx[i]=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        nx[last[a[i]]]=i;
        last[a[i]]=i;
    }
    build(1,1,n);
    mx_suf[n+1]=0;
    for (int i=n; i>=1; i--)
        mx_suf[i]=max(a[i],mx_suf[i+1]);
    int mx=0;
    int last_mx=0;
    for (int i=1; i<=n; i++)
    {
        if (a[i]>=mx)
        {
            mx=a[i];
            last_mx=i;
        }
        int x2=nx[last_mx];
        int x3=last[mx];
        if (x2==0||x3==x2) continue;
        int l=x2,r=n;
        if (mini(1,1,n,i+1,x2)<mx) continue;
        while (r-l>1)
        {
            int mid=(l+r)/2;
            if (mini(1,1,n,i+1,mid)<mx) r=mid; else l=mid;
        }
        int pos=0;
        if (mini(1,1,n,i+1,r)==mx) pos=r; else pos=l;
        pos=min(pos,x3-1);
        if (mx_suf[pos+1]!=mx) continue;
        cout<<"YES\n"<<i<<" "<<pos-i<<" "<<n-pos<<"\n";
        return;
    }
    cout<<"NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}