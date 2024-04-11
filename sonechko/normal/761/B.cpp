#include<bits/stdc++.h>
using namespace std;
const int N = 250 + 11;
const long long MOD = 1e9 + 7;
#define mod %MOD
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ss second
#define ff first
#define ll long long
#define mp make_pair
#define endl "\n"
#define pb push_back
#define y1 ijdj
#define next lzk
#define ld long double
int a[N],b[N],c[N];
int main()
{
    #ifdef LOCAL
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    sync;
    #endif
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
        cin>>b[i];
    for (int j=1; j<=m; j++)
    {
        for (int i=1; i<=n; i++)
            if (a[i]<j) c[i]=m-j+a[i]; else c[i]=a[i]-j;
        sort(c+1,c+n+1);
        int k=0;
        for (int i=1; i<=n; i++)
        if (b[i]!=c[i]) {k=1; break;}
        if (k==0) {cout<<"YES"<<endl; return 0;}
    }
    cout<<"NO"<<endl;
}