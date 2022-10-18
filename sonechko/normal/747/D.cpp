#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
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
#define tab difjke
int a[N];
vector<int> v;
int main()
{
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // LOCAl
    int n,m;
    cin>>n>>m;
    int t=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        if (a[i]<0) t++;
    }
    if (t==0) {cout<<0<<endl; return 0;}
    if (t>m) {cout<<-1<<endl; return 0;}
    int k=0;
    for (int i=1; i<=n; i++)
    {
        if (a[i]<0)
        {
            if (k!=0&&k!=i-1)
            {
                v.pb(i-k-1);
            }
            k=i;
        }
    }
    int ans1=n*2;
    if (a[n]>=0)
    {
        ans1=n-k;
    }
    sort(v.begin(),v.end());
    m-=t;
    int ans=0,glavans=0;
    for (int i=1; i<=n; i++)
        if (a[i]>=0&&a[i-1]<0) ans++; else
        if (a[i]<0&&a[i-1]>=0) ans++;
    glavans=ans;
    if (ans1<=m) ans--;
    k=0;
    for (int i=0; i<v.size(); i++)
    {
        k+=v[i];
        if (k<=m) ans=min(ans,glavans-(i+1)*2);
        if (k+ans1<=m) ans=min(ans,glavans-(i+1)*2-1);
    }
    cout<<ans<<endl;
}