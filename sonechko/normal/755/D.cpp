#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
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
int t[N],n;
int sum(int r)
{
    int res=0;
    for (int i=r; i>=0; i=(i&(i+1))-1)
        res+=t[i];
    return res;
}
void update(int i, int l)
{
    for (int j=i; j<=n; j=(j|(j+1)))
        t[j]+=l;
}
int sum(int l, int r)
{
    if (l<=r) return sum(r)-sum(l-1); else
        return sum(l,n)+sum(1,r);
}
int main()
{
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // LOCAL
    sync;
    int m;
    cin>>n>>m;
    int l=1;
    ll res=1;
    for (int i=1; i<=n; i++)
    {
        int r=l+m;
        if (r>n) r-=n;
        int ans=0,l1=0,r1=0;
        if (m<=n/2) {l1=l+1; r1=r-1;} else
            {
                l1=r+1;
                r1=l-1;
            }
        if (l1>n) l1-=n;
        if (r1>n) r1-=n;
        if (l1<1) l1+=n;
        if (r1<1) r1+=n;
        ans=sum(l1,r1);
        res+=ans+1;
        update(l,1);
        update(r,1);
        l=r;
        cout<<res<<" ";
    }
    cout<<endl;
}