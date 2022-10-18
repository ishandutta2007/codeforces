#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+ 11;
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
#define sqr(a) ((a)*(a))
int up[N],down[N],a[N];
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
    up[n]=0;
    down[n]=0;
    for (int i=n-1; i>=1; i--)
    {
        if (a[i+1]>=a[i]) up[i]=up[i+1]+1;
        if (a[i+1]<=a[i]) down[i]=down[i+1]+1;
    }
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        l+=up[l];
        l+=down[l];
        if (l>=r) {cout<<"Yes"<<endl;} else {cout<<"No"<<endl;}
    }
}