#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ss second
#define ll long long
#define ff first
#define mp make_pair
#define pb push_back
#define sqr(a) ((a)*(a))
int res,a[N],b[N],c[N],d[N];
map<pair<int,int>,bool> mt;
int main()
{
    sync;
    #ifdef LOCAL
    freopen("output.txt", "w", stdout);
    #else
    #endif
    for (int i=1; i<=3; i++)
        {
            cin>>a[i]>>b[i];
    mt[mp(a[i],b[i])]=1;
        }
    for (int i=1; i<=3; i++)
    for (int j=1; j<=3; j++)
    for (int k=1; k<=3; k++)
    if (i!=j&&j!=k&&i!=k)
    {
        int x=a[i]+a[j]-a[k];
        int y=b[i]+b[j]-b[k];
        if (mt[mp(x,y)]==0) {res++; c[res]=x; d[res]=y; mt[mp(x,y)]=1;}
    }
    cout<<res<<endl;
    for (int i=1; i<=res; i++)
        cout<<c[i]<<" "<<d[i]<<endl;
}