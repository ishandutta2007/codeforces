#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll long long
#define ld long double
#define pb push_back

const int N = 1e5 + 11;

int a[N],b[N],c[N],d[N];

int good(int x1, int y1, int x2, int y2)
{
      if (x1==x2&&y1!=y2) return x1;
      if (x1==y2&&y1!=x2) return x1;
      if (y1==x2&&x1!=y2) return y1;
      if (y1==y2&&x1!=x2) return y1;
      return -1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    cin>>a[i]>>b[i];
    for (int i=1; i<=m; i++)
    cin>>c[i]>>d[i];
    vector<int> vv;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    if (good(a[i],b[i],c[j],d[j])!=-1) vv.pb(good(a[i],b[i],c[j],d[j]));
    sort(vv.begin(),vv.end());
    if (vv[0]==vv.back()) {cout<<vv[0]<<endl; return 0;}
    for (int i=1; i<=n; i++)
    {
              vv.clear();
              for (int j=1; j<=m; j++)
              if (good(a[i],b[i],c[j],d[j])!=-1) vv.pb(good(a[i],b[i],c[j],d[j]));
              sort(vv.begin(),vv.end());
              if (vv.size()>0&&vv[0]!=vv.back()) {cout<<"-1"<<endl; return 0;}
    }
    for (int j=1; j<=m; j++)
    {
              vv.clear();
              for (int i=1; i<=n; i++)
              if (good(a[i],b[i],c[j],d[j])!=-1) vv.pb(good(a[i],b[i],c[j],d[j]));
              sort(vv.begin(),vv.end());
              if (vv.size()>0&&vv[0]!=vv.back()) {cout<<"-1"<<endl; return 0;}
    }
    cout<<0<<endl;
}