#include<bits/stdc++.h>
using namespace std;
const int N = 500000 + 11;
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
int main()
{
    sync;
    int n;
    cin>>n;
    int l1=0,r1=INT_MAX;
    for (int i=1; i<=n; i++)
        {
            int l,r;
            cin>>l>>r;
            l1=max(l1,l);
            r1=min(r1,r);
        }
    int m;
    cin>>m;
    int l2=0,r2=INT_MAX;
    for (int i=1; i<=m; i++)
        {
            int l,r;
            cin>>l>>r;
            l2=max(l2,l);
            r2=min(r2,r);
        }
    int ans=0;
    ans=max(ans,(l2-r1));
    ans=max(ans,(l1-r2));
    cout<<ans<<endl;
}