#include<bits/stdc++.h>
using namespace std;

const int N = 3e6 + 11;
int ans[N],a[N],b[N];
string s;

void build(int i, int l, int r)
{
    if (l==r)
    {
        ans[i]=0;
        if (s[l]=='(') {a[i]=1; b[i]=0;} else {a[i]=0; b[i]=1;}
        return;
    }
    int mid=(l+r)/2;
    build(i+i,l,mid);
    build(i+i+1,mid+1,r);
    ans[i]=ans[i+i]+ans[i+i+1];
    int d = min(a[i+i],b[i+i+1]);
    ans[i]+=d*2;
    a[i]=a[i+i]+a[i+i+1]-d;
    b[i]=b[i+i]+b[i+i+1]-d;
}

pair<int,pair<int,int> > get(int i, int l, int r, int tl, int tr)
{
    if (tl<=l&&r<=tr) return make_pair(ans[i],make_pair(a[i],b[i]));
    if (tl>r||l>tr) return make_pair(0,make_pair(0,0));

    int mid=(l+r)/2;
    pair<int,pair<int,int> > p1 = get(i+i,l,mid,tl,tr);
    pair<int,pair<int,int> > p2 = get(i+i+1,mid+1,r,tl,tr);
    pair<int,pair<int,int> > res = make_pair(0,make_pair(0,0));
    res.first = p1.first+p2.first;
    int d = min(p1.second.first, p2.second.second);
    res.first += d*2;
    res.second.first = p1.second.first + p2.second.first - d;
    res.second.second = p1.second.second + p2.second.second - d;
    return res;
}

int main()
{
    cin>>s;
    s="."+s;
    int n=s.size()-1;
    for (int p=1; p<=20; p++)
    if ((1<<p)>=n) {n=(1<<p); break;}
    while (s.size()-1 < n)
        s+="(";
    build(1,1,n);
    int m;
    cin>>m;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        pair<int,pair<int,int> > p = get(1,1,n,l,r);
        cout<<p.first<<"\n";
    }
}
/**
 
1 2 .. n
     
        
**/