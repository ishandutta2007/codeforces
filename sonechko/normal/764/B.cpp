#include<bits/stdc++.h>
using namespace std;
const int N = 200000 + 11;
const long long MOD = 1e9 + 7;
#define mod %MOD
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ss second
#define ff first
#define ll unsigned long long
#define mp make_pair
#define endl "\n"
#define pb push_back
#define y1 ijdj
#define next lzk
#define ld long double
#define sqr(a) ((a)*(a))
int a[N];
int main()
{
    #ifdef LOCAL
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    sync;
    #endif
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    if (n%2==1)
    {
    for (int i=1; i<=n; i++)
        if (i%2==0) cout<<a[i]<<" ";
    else cout<<a[n-i+1]<<" ";
    cout<<endl;
    } else
    {
        for (int i=1; i<=n; i++)
            if (i%2==0&&i<=n/2) cout<<a[i]<<" ";else
            if (i%2==1&&i>n/2) cout<<a[i]<<" "; else
                cout<<a[n-i+1]<<" ";
    }
}