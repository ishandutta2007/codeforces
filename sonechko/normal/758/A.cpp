#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 11;
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
int a[N];
int main()
{
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif // LOCAL
    sync;
    int n;
    cin>>n;
    int maximum=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        maximum=max(a[i],maximum);
    }
    int ans=0;
    for (int i=1; i<=n; i++)
        ans+=maximum-a[i];
    cout<<ans<<endl;
}