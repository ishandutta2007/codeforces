#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int a[N],b[N],c[N],A,B,C;
long long cnk1[N],cnk2[N],cnk3[N];

pair<int,pair<int,int> > find_(int l, int r)
{
    int kol_a=0,kol_b=0,kol_c=0;
    for (int j=1; j<=A; j++)
        if (l<=a[j]&&a[j]<=r) kol_a++;
    for (int j=1; j<=B; j++)
        if (l<=b[j]&&b[j]<=r) kol_b++;
    for (int j=1; j<=C; j++)
        if (l<=c[j]&&c[j]<=r) kol_c++;
    return mp(kol_a,mp(kol_b,kol_c));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>A>>B>>C;
    for (int i=1; i<=A; i++)
        cin>>a[i];
    for (int i=1; i<=B; i++)
        cin>>b[i];
    for (int i=1; i<=C; i++)
        cin>>c[i];
    sort(a+1,a+A+1);
    sort(b+1,b+B+1);
    sort(c+1,c+C+1);
    long long res=0;
    for (int i=1; i<=1000; i++)
    {
        cnk1[i]=i;
        cnk2[i]=i*(i-1)/2;
        /// (i!)/(2!)/((i-2)!) = i*(i-1)/2
        cnk3[i]=i*(i-1)*(i-2)/6;
        /// (i!)/(3!)/((i-3)!) = i*(i-1)*(i-2)/6
    }

    /// If in 1
    for (int d=1; d<=A; d++)
    {
        int min_=a[d];
        pair<int,pair<int,int> > p=find_(min_+1,min_*2);
        int kol_a=p.ff;
        int kol_b=p.ss.ff;
        int kol_c=p.ss.ss;
        if (kol_b>=2&&kol_c>=3) res+=cnk2[kol_b]*cnk3[kol_c];
    }

    /// If in 2
    for (int d=1; d<=B; d++)
    {
        int min_=b[d];
        pair<int,pair<int,int> > p=find_(min_+1,min_*2);
        int kol_a=p.ff;
        int kol_b=p.ss.ff;
        int kol_c=p.ss.ss;
        if (kol_a>=1&&kol_b>=1&&kol_c>=3) res+=cnk1[kol_a]*cnk1[kol_b]*cnk3[kol_c];
    }

    /// If in 3
    for (int d=1; d<=C; d++)
    {
        int min_=c[d];
        pair<int,pair<int,int> > p=find_(min_+1,min_*2);
        int kol_a=p.ff;
        int kol_b=p.ss.ff;
        int kol_c=p.ss.ss;
        if (kol_a>=1&&kol_b>=2&&kol_c>=2) res+=cnk1[kol_a]*cnk2[kol_b]*cnk2[kol_c];
    }

    cout<<res<<endl;
}