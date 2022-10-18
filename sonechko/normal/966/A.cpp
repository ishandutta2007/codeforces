#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 11;

int a[N],b[N];
int nn,mm;

int left_a(int d)
{
    if (nn==0) return -1;
    int l=1,r=nn;
    while (r-l>1)
    {
        int mid=(l+r)/2;
        if (a[mid]<=d) l=mid; else r=mid;
    }
    if (a[r]<=d) return r;
    if (a[l]<=d) return l;
    return -1;
}
int right_a(int d)
{
    if (nn==0) return -1;
    int l=1,r=nn;
    while (r-l>1)
    {
        int mid=(l+r)/2;
        if (a[mid]>=d) r=mid; else l=mid;
    }
    if (a[l]>=d) return l;
    if (a[r]>=d) return r;
    return -1;
}
int left_b(int d)
{
    if (mm==0) return -1;
    int l=1,r=mm;
    while (r-l>1)
    {
        int mid=(l+r)/2;
        if (b[mid]<=d) l=mid; else r=mid;
    }
    if (b[r]<=d) return r;
    if (b[l]<=d) return l;
    return -1;
}
int right_b(int d)
{
    if (mm==0) return -1;
    int l=1,r=mm;
    while (r-l>1)
    {
        int mid=(l+r)/2;
        if (b[mid]>=d) r=mid; else l=mid;
    }
    if (b[l]>=d) return l;
    if (b[r]>=d) return r;
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,v;
    cin>>n>>m>>nn>>mm>>v;
    for (int i=1; i<=nn; i++)
        cin>>a[i];
    for (int i=1; i<=mm; i++)
        cin>>b[i];
    int q;
    cin>>q;
    for (int i=1; i<=q; i++)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        if (x1==x2) cout<<abs(y1-y2)<<"\n"; else
        {
            int ans=2e9;
            int p=left_a(y1);
            if (p!=-1) ans=min(ans,abs(y1-a[p])+abs(x2-x1)+abs(y2-a[p]));
            p=right_a(y1);
            if (p!=-1) ans=min(ans,abs(y1-a[p])+abs(x2-x1)+abs(y2-a[p]));
            p=left_a(y2);
            if (p!=-1) ans=min(ans,abs(y1-a[p])+abs(x2-x1)+abs(y2-a[p]));
            p=right_a(y2);
            if (p!=-1) ans=min(ans,abs(y1-a[p])+abs(x2-x1)+abs(y2-a[p]));
            p=left_b(y1);
            if (p!=-1) ans=min(ans,abs(y1-b[p])+(abs(x2-x1)+v-1)/v+abs(y2-b[p]));
            p=right_b(y1);
            if (p!=-1) ans=min(ans,abs(y1-b[p])+(abs(x2-x1)+v-1)/v+abs(y2-b[p]));
            p=left_b(y2);
            if (p!=-1) ans=min(ans,abs(y1-b[p])+(abs(x2-x1)+v-1)/v+abs(y2-b[p]));
            p=right_b(y2);
            if (p!=-1) ans=min(ans,abs(y1-b[p])+(abs(x2-x1)+v-1)/v+abs(y2-b[p]));
            cout<<ans<<"\n";
        }
    }
}
/**

10 10 1 8 4
10
2 3 4 5 6 7 8 9
1
1 1 3 1
**/