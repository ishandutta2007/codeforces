#include<bits/stdc++.h>
using namespace std;
const int N = 100000 + 11;
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
pair<int,int> p[N];
int a[N],ans[N],c[N];
int main()
{
    #ifdef LOCAL
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    sync;
    #endif
    int n,l,r;
    cin>>n>>l>>r;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
    {
        cin>>p[i].ff;
        p[i].ss=i;
    }
    sort(p+1,p+n+1);
    int k=INT_MIN;
    for (int j=1; j<=n; j++)
    {
        int i=p[j].ss;
        int l1=l-a[i];
        int r1=r-a[i];
        if (r1<=k) {cout<<"-1"<<endl; return 0;}
        k=max(l1,k+1);
        c[i]=k+a[i];
    }
    for (int i=1; i<=n; i++)
        cout<<c[i]<<" ";
    cout<<endl;
}