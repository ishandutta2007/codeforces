#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
const int N = 2e5 + 11;

int v[63][N];
int n;

void update(int ps, int i, int k)
{
    for (int j=i; j<=n; j=(j|(j+1)))
        v[ps][j]+=k;
}
int sum(int ps, int l)
{
    int res=0;
    for (int j=l; j>=0; j=(j&(j+1))-1)
        res+=v[ps][j];
    return res;
}
int sum(int ps, int l, int r)
{
    return sum(ps,r)-sum(ps,l-1);
}
int gg(int cc, int pos, int l1, int r1)
{
    int l=l1,r=r1;
    while (r-l>1)
    {
        int mid=(l+r)/2;
        if (sum(cc,l1,mid)<pos) l=mid; else r=mid;
    }
    if (sum(cc,l1,l)==pos) return l;
    if (sum(cc,l1,r)==pos) return r;
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m;
    cin>>n>>m;
    string s;
    cin>>s;
    s='.'+s;
    for (int i=1; i<=n; i++)
    {
        char ch=s[i];
        int x=0;
        if (ch>='a'&&ch<='z') x=ch-'a'+1;
        if (ch>='A'&&ch<='Z') x=ch-'A'+1+26;
        if (ch>='0'&&ch<='9') x=ch-'0'+1+26+26;
        update(x,i,1);
        update(0,i,1);
    }
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        l=gg(0,l,1,n);
        r=gg(0,r,1,n);
        char ch;
        cin>>ch;
        int x=0;
        if (ch>='a'&&ch<='z') x=ch-'a'+1;
        if (ch>='A'&&ch<='Z') x=ch-'A'+1+26;
        if (ch>='0'&&ch<='9') x=ch-'0'+1+26+26;
        while (1==1)
        {
            int p=gg(x,1,l,r);
            if (p==-1) break;
            update(0,p,-1);
            update(x,p,-1);
        }
    }
    for (int i=1; i<=n; i++)
        if (sum(0,i,i)==1) cout<<s[i];
    cout<<endl;
}