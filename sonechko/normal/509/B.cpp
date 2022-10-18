#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ss second
#define ff first
#define pb push_back
#define mp make_pair
#define y1 kdnfskefn
#define sqr(a) ((a)*(a))
const int N = 1e2 + 11;
///-----------------------------------------------------------
vector<int> v[N];
int a[N];
///-----------------------------------------------------------
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=m; i++)
    {
        int t1=0,t2=0;
        for (int j=1; j<=n; j++)
            if (a[j]>t1) t1=a[j];
        for (int j=1; j<=n; j++)
            if (a[j]>t2&&a[j]!=t1) t2=a[j];
        int ans=t2-t1-1;
        for (int j=1; j<=n; j++)
            if (a[j]<ans) ans=a[j];
        if (t1==0) break;
        for (int j=1; j<=n; j++)
        {
            if (a[j]==t1) {a[j]--; v[j].pb(i);}
            for (int k=1; k<=ans; k++)
                {
                    v[j].pb(i);
                    a[j]--;
                }
        }
    }
    int t1=1000000;
    for (int i=1; i<=n; i++)
        t1=min(t1,a[i]);
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=t1; j++)
            v[i].pb(1);
        a[i]-=t1;
    }
    for (int i=1; i<=n; i++)
    if (a[i]!=0) {cout<<"NO"<<endl; return 0;}
    cout<<"YES"<<endl;
    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<v[i].size(); j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
}